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

const int maxn = 2 * 1e5 + 5;

int T, N;
ll arr[maxn];
ll pre[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i];

		pre[0] = pre[1] = 0;
		FOR (i, 2, N + 1)
			pre[i] = pre[i - 2] + arr[i - 2] * arr[i - 1];

		/* FOR (i, 0, N + 1) */
			/* cout << pre[i] << ' '; */
		/* cout << '\n'; */

		ll ans = 0, t;
		FOR (i, 0, N) {
			ll mx = -1e9;
			FOR (j, i + 1, N + 1) {
				mx = max(mx, arr[j - 1]);
				t = j - ((j - i) % 2);
				ans = max(ans, mx * mx + pre[t] - pre[i]);
			}
		}

		cout << ans << '\n';
	}

    return 0;
}
