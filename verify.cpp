#include <vector>
#include "globals.h"

using namespace std;

void compare (  int a,  int b, vector<int> * x )
{
	for ( int i = 0; i < sigma; i++ )
	{
		if ( pattern[a][i] == text[b][i] )
		{
			x->push_back (i );
		}
	}
}

bool verify (  int a,  int b, double pp, double tp )
{
	bool flag = false;
	vector<int> v;
	compare ( a, b, &v );
	if ( v.size() != 0 )
	{
		for ( int i = 0; i < v.size(); i++ )
		{
			int l = v[i];
			double pp2 = pp * pattern[a][l];
			double tp2 = tp * text[b][l];
			if ( pp2 >=z && tp2 >= z )
			{
				if ( a + 1 < m && b + 1 < n )
					flag = verify ( a+1, b+1, pp2, tp2 );
				else
					flag = true;
			}
		}
	}
	return flag;
}
