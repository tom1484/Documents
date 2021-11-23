#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 100005;

int V, E;
vector<int> edges[maxn];
int clr[maxn];

bool ans;

void dfs(int s) {
	
	for (int u: edges[s]) {
		if (!clr[u]) {
			clr[u] = 3-clr[s];
			dfs(u);
		} 
		if (clr[s] == clr[u])
			ans = false;
		if (!ans)
			return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	cin >> V;
	while (V) {
		memset(edges, 0, sizeof edges);
		memset(clr, 0, sizeof clr);

		cin >> E;
		FOR (i, 0, E) {
			cin >> a >> b;
			edges[a].pb(b);
			edges[b].pb(a);
		}

		clr[0] = 1;
		ans = true;
		dfs(0);

		if (ans)
			cout << "NORMAL.\n";
		else
			cout << "RAINBOW.\n";

		cin >> V;
	}

    return 0;
}
