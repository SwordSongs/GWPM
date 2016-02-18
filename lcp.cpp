#include <vector>

#include "defs.h"
#include "globals.h"

using namespace std;

int LCP ( vector<int> x, int a, int * xx, int b )
{
	int lcp = a;
	for ( int i = a; i < x.size(); i ++)
	{
		if ( x[i] == xx[i+b] )
			lcp++;
		else
			break;
	}
	return lcp;
}
