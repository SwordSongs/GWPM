#include <string>
#include <vector>

#define DNA		"ACGT"

using namespace std;

#ifndef TSWITCH_H
#define TSWITCH_H
struct TSwitch
{
	double z;
	string pattern_file_name;
	string text_file_name;
	string output_file_name;
};
#endif

#ifndef PSTR_H
#define PSTR_H
struct Pstr
{
	double pro;
	vector <int> str;
};
#endif

#ifndef INDEX_H
#define INDEX_H
class PatternIndex
{
	public:
		PatternIndex	( int * x, int m, int sigma );
		int SA  ( int i ); 
		int iSA ( int i );
		int LCP ( int i );
	private:
		int * sa;
		int * isa;
		int * lcp;
};
#endif

int decode_switches ( int argc, char * argv[], TSwitch * sw );
void usage ( void );
int read ( string filename, char mod );
void suffixArray ( int * s, int * SA, int n, int K );
void match ( vector<int> *Occ );
void validlist ( int a, int q, Pstr ps, vector <Pstr> * list, char mod );
//bool verify ( int a, int b, double pp, double tp );
bool verify ( int pos_text, vector<Pstr> &patternlist);
int LCP ( vector<int> x, int a, int* xx, int b );
