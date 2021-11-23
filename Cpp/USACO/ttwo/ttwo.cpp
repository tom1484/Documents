/*
ID: angelus6
TASK: ttwo
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

bool arr[10][10];
pii pos[2];

bool vis[100][4][100][4] = {};

int main() {

	char c;
	FOR (i, 0, 10)
		FOR (j, 0, 10) {
			cin >> c;
			arr[i][j] = c != '*';
			if (c == 'C' || c == 'F')
				pos[c == 'C'] = make_pair(i, j);
		}

	

	return 0;
}
