#include <vector>
#include "defs.h"
#include "util.h"

using namespace std;

PatternIndex::PatternIndex ( int * x, int m, int sigma )
{
	sa	= new  int [m+3];
	isa = new  int [m];
	lcp = new  int [m];

	sa[m] = sa[m+1] = sa[m+2] = 0;

	suffixArray ( x, sa, m, sigma );

	for ( int i = 0; i < m; i++ )
		isa[ sa[i] ] = i;
	lcp[0] = 0;
	int j = 0;
	for ( int i = 0; i < m; i++ )
	{
		if ( isa[i] != 0 )
		{
			if ( i == 0 ) j = 0;
			else j = ( lcp[isa[i-1]] >=2 ) ? lcp[isa[i-1]]-1 : 0;
			while ( x[i+j] == x[sa[isa[i]-1]+j] )
				j++;
			lcp[isa[i]] = j;
		}
	}
}

int PatternIndex::SA ( int i ) {
	return sa[i];
}

int PatternIndex::iSA ( int i ) {
	return isa[i];
}

int PatternIndex::LCP ( int i ) {
	return lcp[i];
}
