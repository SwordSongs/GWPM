#include <vector>
#include <string>
#include <iostream>

#include "defs.h"
#include "globals.h"

using namespace std;

void validlist ( int a, int q, Pstr ps, vector<Pstr> * list, char mod )
{
	double p = ps.pro;
	if ( a == q )
	{
		list->push_back ( ps );
	}
	else
	{
		if ( mod == 't' )
		{
			for ( int i = 0; i < sigma; i++ )
			{
				if ( p * text[a][i] >= z )
				{
					Pstr ps2;
					ps2.pro = p * text[a][i];
					ps2.str = ps.str;
					ps2.str.push_back ( i + 1 );
					validlist ( a + 1, q, ps2, list, 't' );
				}
			}
		}
		else if ( mod == 'p' )
		{
			for ( int i = 0; i < sigma; i++ )
			{
				if ( p * pattern[a][i] >= z )
				{
					Pstr ps3;
					ps3.pro = p * pattern[a][i];
					ps3.str = ps.str;
					ps3.str.push_back ( i + 1 );
					validlist ( a + 1, q, ps3, list, 'p' );
				}
			}
		}
	}
}

