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

const int maxn = 5005;
const int MOD = 1000000007;

int N, p, ans = 0;
int arr[maxn], tag[maxn], dp[maxn];
vector<int> v;

bool cmp(int a, int b) {
	return a > b;
}

int mod(int x) {
	return x % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	FOR (i, 0, N) 
		cin >> arr[i];

	v.pb(arr[N - 1]);
	RFOR (i, N - 1, 0) {
		p = upper_bound(v.begin(), v.end(), arr[i], cmp) - v.begin();
		if (p < v.size())
			v[p] = arr[i];
		else
			v.pb(arr[i]);
		tag[i] = p;
	}
	cout << v.size() << '\n';

	FOR (i, 0, N)
		dp[i] = (tag[i] == v.size() - 1);

	FOR (i, 1, N) {
		FOR (j, 0, i)
			if (arr[j] <= arr[i] && tag[j] - tag[i] == 1)
				dp[i] = mod(dp[i] + dp[j]);
		if (tag[i] == 0)
			ans = mod(ans + dp[i]);
	}
	cout << ans << '\n';

	/* FOR (i, 0, N) */
		/* cout << setw(2) << arr[i] << ' '; */
	/* cout << '\n'; */

	/* FOR (i, 0, N) */
		/* cout << setw(2) << tag[i] << ' '; */
	/* cout << '\n'; */

	/* FOR (i, 0, N) */ 
		/* cout << setw(2) << dp[i] << ' '; */
	/* cout << '\n'; */

	p = v.size() - 1;
	FOR (i, 0, N)
		if (p == tag[i]) {
			cout << i + 1 << ' ';
			p--;
		}

    return 0;
}
