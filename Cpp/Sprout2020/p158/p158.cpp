#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 101;
const int maxk = 101;
const int maxm = 1001;

int T, N, K, M;
int w[maxn], c[maxn];
int dp[maxk][maxm];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		FOR (i, 0, N)
			cin >> w[i] >> c[i];


		int ans = 0;
		memset(dp, 0, sizeof dp);

		FOR (n, 0, N) {
			RFOR (m, M, w[n]) {
				FOR (k, 1, K + 1) {
					dp[k][m] = max(dp[k][m], dp[k - 1][m - w[n]] + c[n]);
					ans = max(ans, dp[k][m]);
				}
			}
		}

		cout << ans << '\n';
	}

    return 0;
}
