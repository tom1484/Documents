#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const ll maxn = 100005;

struct Edge {
	ll u, v, w;
	ll tag;

	Edge() {}

	Edge(ll u, ll v, ll w, ll tag): 
		u(u), v(v), w(w), tag(tag) {}
};

ll N, M, S;

vector<Edge> G[maxn];

ll dis[maxn] = {};
bool vis[maxn] = {};
Edge pre[maxn] = {};
bool dir[maxn] = {};

bool used[maxn] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> S;
	
	FOR (i, 1, M) {
		ll u, v, w;
		cin >> u >> v >> w;
		G[u].pb(Edge(u, v, w, 0));
	}

	FOR (i, 1, S) {
		ll v, w;
		cin >> v >> w;
		G[1].pb(Edge(1, v, w, i));
	}

	FOR (i, 2, N) {
		dis[i] = 1e18;
	}

	priority_queue<pair<ll, ll>> Q;
	Q.push(make_pair(0, 1));

	while (!Q.empty()) {
		ll u = Q.top().second;
		Q.pop();
		if (vis[u])
			continue;
		vis[u] = true;

		for (Edge &e: G[u]) {
			if (dis[u] + e.w < dis[e.v]) {
				dis[e.v] = dis[u] + e.w;
				pre[e.v] = e;
				dir[e.v] = dir[u] || e.tag;
				Q.push(make_pair(dis[e.v], e.v));
			}
			if (dis[u] + e.w == dis[e.v] && !(dir[u] || e.tag)) {
				pre[e.v] = e;
				dir[e.v] = false;
				Q.push(make_pair(dis[e.v], e.v));
			}
		}
	}

	/* FOR (i, 1, N) */
	/* 	cout << dis[i] << " "; */
	/* cout << '\n'; */

	ll cnt = 0;
	FOR (i, 2, N) {
		ll p = i;
		Edge e = pre[p];
		while (true) {
			/* cout << p << ' '; */
			if (e.tag && !used[e.tag]) {
				cnt++;
				used[e.tag] = true;
			}
			p = e.u;
			if (p == 1)
				break;
			e = pre[p];
		}
		/* cout << '\n'; */
	}

	cout << S - cnt << '\n';

    return 0;
}
