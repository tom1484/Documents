/*
ID: angelus6
TASK: nocows
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
ifstream fin("nocows.in");
ofstream fout("nocows.out");

int N, K;
int dp[105][205] = {};

int main() {

	cin >> N >> K;
	dp[0][0] = dp[1][1] = 1;
	FOR (i, 2, K+1)
		FOR (j, 1, N+1)
			FOR (k, 1, j)
				FOR (l, 1, i) {
					int t = dp[i-1][k]*dp[l][j-1-k];
					if (i-1 == l)
						dp[i][j] += t;
					else
						dp[i][j] += t*2;
					dp[i][j] %= 9901;
				}
	cout << dp[K][N] << '\n';

	return 0;
}
