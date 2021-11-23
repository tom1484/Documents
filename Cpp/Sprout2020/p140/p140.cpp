#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 1e5 + 1;
const int MOD = 1000007;

int T, N;
int dp[maxn][3];
int b[maxn][3];
int g[maxn][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof dp);
	memset(dp, 0, sizeof b);
	memset(dp, 0, sizeof g);

	FOR (i, 0, 3)
		dp[1][i] = 1;
	b[1][0] = 0, b[1][1] = 0, b[1][2] = 0;
	b[2][0] = 1, b[2][1] = 1, b[2][2] = 0;
	g[1][0] = 0, g[1][1] = 0, g[1][2] = 1;
	g[2][0] = 1, g[2][1] = 0, g[2][2] = 1;

	FOR (i, 2, maxn) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
	}

	FOR (i, 3, maxn) {
		b[i][0] = (b[i - 1][0] + b[i - 1][1] + b[i - 1][2]) % MOD;
		b[i][1] = (b[i - 1][0] + b[i - 1][1]) % MOD;
		b[i][2] = (b[i - 1][0] + b[i - 1][2]) % MOD;
		g[i][0] = (g[i - 1][0] + g[i - 1][1] + g[i - 1][2]) % MOD;
		g[i][1] = (g[i - 1][0] + g[i - 1][1]) % MOD;
		g[i][2] = (g[i - 1][0] + g[i - 1][2]) % MOD;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << ((dp[N][0] + dp[N][1] + dp[N][2] - b[N][2] - g[N][1]) % MOD + MOD) % MOD << '\n';
	}

    return 0;
}
