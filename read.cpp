#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "defs.h"
#include "globals.h"

using namespace std;

int read ( string filename, char mod )
{
	srand ( time ( NULL ) );
	ifstream input ( filename );
	if ( !input.good() )
	{
		cout << "Error: Cannot open file " << filename << ".\n";
		return -1;
	}

	string line, name, content;
	int i = 0;
	int x;
	while ( getline ( input, line ).good() && i < 2 )
	{
		if ( line.empty() || line[0] == '>' )
		{	//Identifier marker
			i++;
			if ( !name.empty() )
			{
				//Print out what we read from the last entry
				name.clear();
			}
			if ( !line.empty() )
			{
				name = line.substr(1);
			}
		}
		else if ( !name.empty() )
		{
			if ( line.find(' ') != string::npos )
			{
				// Invalid sequence--no spaces allowed
				name.clear();
			}
			else
			{
				content += line;
			}
		}
	}

	int length = content.size();
	double ** dna;
	dna = new double * [length];
	for (  int i = 0; i < length; i++ )
	{
		dna[i] = new double [4];
		dna[i][0] = dna[i][1] = dna[i][2] = dna[i][3] = 0;
	}
	for (  int i = 0; i < length; i++ )
	{
		switch ( content[i] )
		{
			case 'A':
				dna[i][0] = 1;
				break;
			case 'C':
				dna[i][1] = 1;
				break;
			case 'G':
				dna[i][2] = 1;
				break;
			case 'T':
				dna[i][3] = 1;
				break;
			case 'N':
				dna[i][0] =	dna[i][1] = dna[i][2] = dna[i][3] = 0.25;
			/*	
				if ( m == 't' )
				{
					x = rand() % 4;
					dna[i][x] = 1;
				}
			*/
				break;
			case 'R':
				dna[i][0] = dna[i][2] = 0.5;
				break;
			case 'Y':
				dna[i][1] = dna[i][3] = 0.5;
				break;
			case 'S':
				dna[i][1] = dna[i][2] = 0.5;
				break;
			case 'W':
				dna[i][0] = dna[i][3] = 0.5;
				break;
			case 'K':
				dna[i][2] = dna[i][3] = 0.5;
				break;
			case 'M':
				dna[i][0] = dna[i][1] = 0.5;
				break;
			case 'B':
				dna[i][1] = dna[i][2] = dna[i][3] = 0.33;
				break;
			case 'D':
				dna[i][0] = dna[i][2] = dna[i][3] = 0.33;
				break;
			case 'H':
				dna[i][0] = dna[i][1] = dna[i][3] = 0.33;
				break;
			case 'V':
				dna[i][1] = dna[i][2] = dna[i][0] = 0.33;
				break;
		}
	}
	
	if ( mod == 't' )
	{
		text = dna;
		n = length;
	}
	if ( mod == 'p' )
	{
		pattern = dna;
		m = length;
	}
	return 1;
}




