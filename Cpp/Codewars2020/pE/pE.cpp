#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int N;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	FOR (j, 1, N)
		for(int i = 1; i + j <= N; i++) {
			dp[i][i + j] = 1e9;
			for(int k = i; k <= i + j; k++)
				dp[i][i + j] = min(dp[i][i + j], k + max(dp[i][k - 1], (k + 1 > i + j) ? 0 : dp[k + 1][i + j]));
		}

	cout << dp[1][N];

	return 0;
}
