#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 2 * 1e5 + 5;

ll N, K;
pll arr[maxn];
priority_queue<ll, vector<ll>, greater<ll>> Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	FOR (i, 0, N) 
		cin >> arr[i].ft >> arr[i].sd;
	sort(arr, arr + N);

	/* FOR (i, 0, N) */
		/* cout << arr[i].ft << ' ' << arr[i].sd << '\n'; */

	ll ans = 0xc0c0c0c0c0c0c0c0;
	FOR (i, 0, N) {
		if (Q.size() < K - 1)
			Q.push(arr[i].sd);
		else {
			/* cout << Q.top() << '\n'; */
			ans = max(ans, min(arr[i].sd, Q.top()) - arr[i].ft);
			Q.push(arr[i].sd);
			Q.pop();
		}
	}

	cout << ans << '\n';

    return 0;
}
