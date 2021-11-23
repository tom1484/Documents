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

const ll maxn = 1e5 + 5;

ll N, M, R, K;

vector<pii> stand;
priority_queue<ll> ready;

bool valid(ll x) {
	ll s = K * x;
	return s / 100 >= M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;
	K = M;

	int p, c;
	FOR (i, 0, N) {
		cin >> p >> c;
		stand.pb(mp(p, c));
	}
	sort(stand.begin(), stand.end());

	ll t = 0, att = 0;
	while (M > 0 && t <= 2 * maxn) {
		M = min(K, M - att + R);
		/* cout << M << ' '; */
		while (stand.size() && valid(stand.back().ft)) {
			ready.push(stand.back().sd);
			stand.pop_back();
		}
		if (!ready.empty()) {
			att += ready.top();
			ready.pop();
		}
		t ++;
	}

	if (t > 2 * maxn)
		cout << -1 << '\n';
	else
		cout << t - 1 << '\n';

    return 0;
}
