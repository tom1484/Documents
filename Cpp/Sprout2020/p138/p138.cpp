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

int dp1[maxn][2];
int dp2[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	FOR (i, 0, 3)
		dp1[0][i] = 0;
	dp2[0] = 1;
	dp2[1] = 0;
	dp2[2] = 3;
	dp1[1][0] = 1;
	dp1[1][1] = 1;
	dp1[2][0] = 0;
	dp1[2][1] = 0;

	FOR (i, 3, maxn) {
		dp1[i][0] = dp2[i - 1] + dp1[i - 2][0];
		dp1[i][0] %= MOD;
		dp1[i][1] = dp2[i - 1] + dp1[i - 2][1];
		dp1[i][1] %= MOD;
		FOR (j, 0, 2)
			dp2[i] += dp1[i - 1][j];
		dp2[i] += dp2[i - 2];
		dp2[i] %= MOD;
	}

	/* FOR (i, 0, 2) { */
		/* FOR (j, 0, 10) */
			/* cout << dp1[j][i] << ' '; */
		/* cout << '\n'; */
	/* } */
	/* FOR (i, 0, 10) */
		/* cout << dp2[i] << ' '; */
	/* cout << '\n'; */

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp2[N] << '\n';
	}

    return 0;
}
