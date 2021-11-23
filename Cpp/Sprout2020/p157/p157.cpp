#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 101;
const int maxc = 1e4 + 1;

int T, N, M;
int w[maxn], c[maxn];
int dp[maxc];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		int s = 0;
		FOR (i, 0, N) {
			cin >> w[i] >> c[i];
			s += c[i];	
		}
		
		int ans = 0;
		memset(dp, 0x3f3f3f3f, sizeof dp);
		dp[0] = 0;
		FOR (i, 0, N) {
			RFOR (j, s + 1, 0) {
				if (j >= c[i])
					dp[j] = min(dp[j], dp[j - c[i]] + w[i]);
				if (dp[j] <= M)
					ans = max(ans, j);
			}
		}

		cout << ans << '\n';
	}

    return 0;
}
