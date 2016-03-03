#include <iostream>
#include <vector>
#include "defs.h"
#include "util.h"

using namespace std;

PatternIndex::PatternIndex ( int * x, int l, int sigma )
{
	sa	= new  int [l+3];
	isa = new  int [l];
	lcp = new  int [l];

	sa[l] = sa[l+1] = sa[l+2] = 0;
	suffixArray ( x, sa, l, sigma );

	for ( int i = 0; i < l; i++ )
		isa[ sa[i] ] = i;
	lcp[0] = 0;
	int j = 0;
	for ( int i = 0; i < l; i++ )
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
