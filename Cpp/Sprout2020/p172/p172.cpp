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

const ll maxn = 105;
const ll MOD = 1000007;

ll T, N, M;

ll arr[maxn];
ll dp[maxn][maxn];

ll C[maxn][maxn];
ll tmp[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(C, 0, sizeof C);
	FOR (i, 0, maxn) {
		FOR (j, 0, i + 1) {
			C[i][j] = 1;
			FOR (k, 1, i - j + 1)
				tmp[k] = k;
			
			FOR (k, j + 1, i + 1) {
				ll t = k;
				FOR (l, 1, i - j + 1)
					if (tmp[l]) {
						ll g = __gcd(t, tmp[l]);
						if (g > 1) {
							t /= g;
							tmp[l] /= g;
						}
					}
				C[i][j] = (C[i][j] * t) % MOD;
			}
		}
	}

	/* cout << C[100][50] << '\n'; */
	
	cin >> T;
	while (T--) {
		cin >> N >> M;
		FOR (i, 0, N)
			cin >> arr[i];
		
		memset(dp, 0, sizeof dp);
		dp[0][M - arr[0]] = C[M][arr[0]];
		
		FOR (i, 1, N) {
			FOR (j, 0, M + 1) {
				FOR (k, j, j + arr[i] + 1) {
					if (k > M || k - j > k || arr[i] + j > M)
						break;
					dp[i][j] = (dp[i][j] + (dp[i - 1][k] * C[k][k - j]) % MOD * C[M - k][arr[i] - (k - j)]) % MOD;
				}
			}
		}
		
		cout << dp[N - 1][0] << '\n';

	}

    return 0;
}
