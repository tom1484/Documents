#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

struct Arc {
	int from, to, cap, flow, res;
	
	Arc() {}

	Arc(int from, int to, int cap): from(from), to(to), cap(cap) {
		flow = 0;
		res = cap-flow;
	}

	void add(int val) {
		flow += val;
		res -= val;
	}
};

struct Flow {
	int V, src, tar;
	vector<Arc> arcs;
	vector<int> G[105];

	void init(int _V, int _src, int _tar) {
		V = _V;
		src = _src;
		tar = _tar;

		for (int i = 0; i < 105; i++)
			G[i].clear();
		arcs.clear();
	}

	void addArc(int from, int to, int cap) {
		arcs.pb(Arc(from, to, cap));
		arcs.pb(Arc(to, from, cap));
		int m = arcs.size()-1;
		G[from].pb(m-1);
		G[to].pb(m);
	}

	int maxFlow() {
		int flow = 0;
		int prev[105], aug[105];
		queue<int> q;

		while (true) {
			for (int& x: aug)
				x = 0;

			q.push(src);
			aug[src] = 1e9;
			while (!q.empty()) {
				int s = q.front();
				q.pop();

				for (int arc: G[s]) {
					int to = arcs[arc].to, res = arcs[arc].res;
					if (aug[to] || res <= 0)
						continue;
					prev[to] = arc;
					aug[to] = min(res, aug[s]);
					q.push(to);
				}
			}

			int res = aug[tar];
			if (!res)
				break;

			for (int arc = prev[tar]; ; arc = prev[arcs[arc].from]) {
				arcs[arc].add(res);
				arcs[arc^1].add(-res);
				if (arcs[arc].from == src)
					break;
			}
			flow += res;
		}

		return flow;
	}
} f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, s, t, E, cnt = 1;
	
	while (cin >> N) {
		if (!N)
			break;
		cin >> s >> t >> E;
		f.init(N, s-1, t-1);

		int u, v, c;
		FOR (i, 0, E) {
			cin >> u >> v >> c;
			f.addArc(u-1, v-1, c);
		}

		int ans = f.maxFlow();
		printf("Network %d\n", cnt);
		printf("The bandwidth is %d.\n", ans);
		
		cnt++;
	}

	return 0;
}
