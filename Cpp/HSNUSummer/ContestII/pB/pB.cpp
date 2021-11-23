#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const ll maxn = 200005;

ll N;

ll arr[maxn][3];

vector<ll> G[maxn];
bool vis[maxn];

ll solve(ll s, ll c1, ll c2) {
	if (vis[s])
		return 0;

	vis[s] = true;

	ll c = 3 - c1 - c2;
	ll ans = arr[s][c];

	for (ll x: G[s])
		ans += solve(x, c2, c);
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	FOR (i, 0, 3)
		FOR (j, 0, N)
			cin >> arr[j][i];

	ll u, v;

	FOR (i, 0, N - 1) {
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	ll s;

	FOR (i, 0, N) {
		if (G[i].size() > 2) {
			cout << -1 << '\n';
			return 0;
		}
		if (G[i].size() == 1)
			s = i;
	}

	u = s;
	v = G[u][0];
	s = G[v][0] + G[v][1] - u;

	ll ans = 0, t;

	FOR (i, 0, 3)
		FOR (j, 0, 3)
			if (i != j) {
				FOR (k, 0, N)
					vis[k] = false;
				vis[u] = vis[v] = true;

				t = arr[u][i] + arr[v][j];
				t += solve(s, i, j);
				
				ans = max(ans, t);
			}

	cout << ans << '\n';


    return 0;
}
