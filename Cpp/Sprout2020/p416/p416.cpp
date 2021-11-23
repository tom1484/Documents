#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 2000 + 5;
const int maxk = 2000 + 5;
const int MOD = 1000000007;

int N, K, a, b;
int dp[maxk][maxn];
int pre[maxn];

int mod(int x) {
	return x % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> a >> b >> K;
	if (a > b) {
		a = N - a + 1;
		b = N - b + 1;
	}
	N -= N - b + 1;

	FOR (i, 1, N) {
		if (abs(i - a) > abs(N - a) || i == a)
			dp[1][i] = 0;
		else
			dp[1][i] = 1;
	}
	pre[0] = 0;

	int rt;
	FOR (k, 2, K) {
		FOR (n, 1, N)
			pre[n] = mod(pre[n - 1] + dp[k - 1][n]);
		FOR (n, 1, N) {
			rt = (n + N) / 2;
			dp[k][n] = mod(mod(pre[rt] - dp[k - 1][n]) + MOD);
		}
	}

	/* FOR (k, 1, K) { */
		/* FOR (n, 1, N) */
			/* cout << setw(4) << dp[k][n] << ' '; */
		/* cout << '\n'; */
	/* } */

	int ans = 0;
	FOR (n, 1, N)
		ans = mod(ans + dp[K][n]);
	cout << ans << '\n';

    return 0;
}
