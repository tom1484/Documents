/**
ID: angelus6
TASK: ariprog
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define FOR(i, a, b) for (uint i = a; i <= b; i++)
#define RFOR(i, a, b) for (uint i = a; i >= b; i--)
#define cin fin
//#define cout fout
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

uint n, m, maxv, maxd;
bool valid[250*250*2+1];
vector<int> num;

int main () {
	
	cin >> n >> m;
	memset(valid, 0, sizeof valid);
	FOR (i, 0, m)
		FOR (j, 0, m)
			valid[i*i+j*j] = true;
	maxv = m*m*2;
	maxd = maxv/(n-1);



	return 0;
}
