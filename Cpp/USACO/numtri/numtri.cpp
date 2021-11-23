/*
ID: angelus6
TASK: numtri
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a-1; i >= b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("numtri.out");
ifstream fin ("numtri.in");

int r;
int arr[1000][1000];
int dp[1000][1000];

int main() {

	cin >> r;
	FOR (i, 0, r)
		FOR (j, 0, i+1)
			cin >> arr[i][j];
	
	dp[0][0] = arr[0][0];
	FOR (i, 1, r)
		FOR (j, 0, i+1) {
			if (j == 0)
				dp[i][j] = dp[i-1][j];
			if (j == i)
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
			dp[i][j] += arr[i][j];
		}

	int ans = 0;
	FOR (i, 0, r)
		ans = max(ans, dp[r-1][i]);
	cout << ans << '\n';

	return 0;
}
