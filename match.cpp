#include <string>
#include <vector>
#include <cmath>

#include <sdsl/rmq_support.hpp>

#include "defs.h"
#include "globals.h"

using namespace std;
using namespace sdsl;

void match ( vector<int> * Occ )
{
	int i, j, k;
	int q = ceil ( 3 * log(m) / log(2) );

	Pstr wps;
	wps.pro = 1;
	vector<Pstr> patternlist;
	validlist ( 0, m, wps, &patternlist, 'p' );
	int num_vp = patternlist.size();
	int M = ( m + 1 ) * num_vp - 1;

	int * xx = new int [M+3];
	for ( i = 0; i < num_vp; i++ )
	{
		for ( j = 0; j < m; j++ )
			xx[i*(m+1)+j] = patternlist[i].str[j];
		xx[(i+1)*m] = sigma + 1;
	}
	xx[M] = xx[M+1] = xx[M+2] = 0;

	PatternIndex I ( xx, M, sigma );

	vector<int> v ( M, 0 );
	for ( i = 0; i < M; i++ )
		v[i] = I.LCP(i);
	rmq_succinct_sct<> rmq ( &v );

	i = 0;
	j = m - q;
	while ( i < n - m + 1 )
	{
		Pstr qstr;
		qstr.pro = 1;
		vector<Pstr> qlist;

		validlist ( j, j+q, qstr, &qlist, 't' );

		int flag = 0;
		for ( k = 0; k < qlist.size(); k++ )
		{
			vector<int> x = qlist[k].str;
			int l = 0;
			int r = 0;
			l = LCP ( x, 0, xx, I.SA(0) );
			r = LCP ( x, 0, xx, I.SA(M-1) );

			if ( l == q || r == q )
			{
				flag = 1;
				break;
			}
			else if ( x[l] <= xx[l+I.SA(0)] )
				continue;
			else if ( r < q && x[r] >= xx[r+I.SA(M-1)] )
				continue;
			else
			{
				int L = 0;
				int R = M - 1;
				int c = 0;
				while ( L+1 < R )
				{
					int C = ( L+R ) / 2;
					if ( l >= r )
					{
						if ( I.LCP( rmq(L+1,C) ) >= l )
						{
							c = LCP ( x, l, xx, I.SA(C) );
						}
						else
						{
							c = I.LCP ( rmq(L+1,R) );
						}
					}
					else
					{
						if ( I.LCP ( rmq(C+1,R) ) >= r )
						{
							c = LCP ( x, r, xx, I.SA(C) );
						}
						else
						{
							c = I.LCP ( rmq(C+1,R) );
						}
					}
					if ( c == q )
					{
						flag = 1;
						break;
					}
					else
					{
						if ( x[c] <= xx[c+I.SA(C)] )
						{
							R = C;
							r = c;
						}
						else
						{
							L = C;
							l = c;
						}
					}
				}
			}
		}
		if ( flag )
		{
			/* verify */
			if ( verify ( 0, i, 1, 1 ) )
			{
				Occ->push_back ( i );
			}
			i += 1;
			j += 1;
		}
		else
		{
			/* skip */
			i += m - q;
			j += m - q;
		}
		vector<Pstr>().swap ( qlist );
	}
}
			
	

									


