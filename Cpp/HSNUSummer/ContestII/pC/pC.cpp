#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const ll maxn = 100005;
const ll maxm = 1000005;

struct Edge{
	ll a, b, w;
	Edge() {}
	Edge(ll x, ll y):
		a(x), b(y) {}
};

ll N, M, a, b;

vector<Edge> edges;
vector<pll> G[maxn];

bool vis[maxn], done;
vector<ll> circ;

ll prt[maxn];

ll find(ll x) {
	return prt[x] == x ? x : prt[x] = find(prt[x]);
}

void uni(ll x, ll y) {
	prt[find(x)] = find(y);
}

void dfs(ll s, ll t) {
	if (s == t) {
		done = true;
		return ;
	}

	if (vis[s])
		return ;
	vis[s] = true;

	for (pii p: G[s]) {
		circ.pb(p.sd);
		dfs(p.ft, t);
		if (done)
			return ;
		circ.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool con = false;
	ll mW = 1e9;

	cin >> N >> M;
	cin >> a >> b;
	if (a > b)
		swap(a, b);

	edges.resize(M);
	for (Edge &e: edges) {
		cin >> e.a >> e.b >> e.w;
		if (e.a > e.b)
			swap(e.a, e.b);
		if (a == e.a && b == e.b)
			mW = min(mW, e.w);
	}

	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
			return e1.w < e2.w;
			});

	FOR (i, 0, N)
		prt[i] = i;

	ll cnt = 0;

	FOR (i, 0, edges.size()) {
		Edge &e = edges[i];
		if (find(e.a) != find(e.b)) {
			uni(e.a, e.b);
			G[e.a].pb(mp(e.b, i));
			G[e.b].pb(mp(e.a, i));
			cnt++;
			if (a == e.a && b == e.b)
				con = true;
		}
	}

	if (cnt < N - 2) {
		cout << -1 << '\n';
		return 0;
	}

	if (cnt == N - 2) {
		if (con)
			cout << -1 << '\n';
		else
			cout << 1000000001 << '\n';
		return 0;
	}

	if (con) {
		if (mW > 1)
			cout << mW - 1 << '\n';
		else
			cout << -1 << '\n';
		return 0;
	}

	FOR (i, 0, N)
		vis[i] = 0;
	done = false;
	dfs(a, b);

	ll MW = 0;
	for (ll x: circ)
		MW = max(MW, edges[x].w);
	cout << MW - 1 << '\n';

    return 0;
}
