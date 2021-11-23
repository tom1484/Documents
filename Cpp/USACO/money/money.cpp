/*
ID: angelus6
TASK: money
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
ifstream fin("money.in");
ofstream fout("money.out");

ll V, N;
ll coin[25];
ll dp[10001] = {};

int main() {

	cin >> V >> N;
	FOR (i, 0, V)
		cin >> coin[i];

	dp[0] = 1;
	FOR (i, 0, V)
		FOR (j, 1, N+1)
			if (j >= coin[i])
				dp[j] += dp[j-coin[i]];
	cout << dp[N] << '\n';

	return 0;
}
