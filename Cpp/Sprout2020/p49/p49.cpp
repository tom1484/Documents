#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

const int maxn = 100005;

int T, N, M, Q;
int a, b;

int sz[maxn];
vector<int> tree[maxn];

int dfs(int i) {
	
	for (int x: tree[i])
		sz[i] += dfs(x);
	
	return sz[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	while (T--) {
		memset(sz, 0, sizeof sz);
		memset(tree, 0, sizeof tree);

		cin >> N >> M;
		FOR (i, 0, M) {
			cin >> a >> b;
			tree[a].pb(b);
			sz[b] = 1;
		}

		FOR (i, 1, N+1)
			if (!sz[i]) {
				sz[i]++;
				dfs(i);
			}

		cin >> Q;
		FOR (i, 0, Q) {
			cin >> a;
			cout << sz[a] << '\n';
		}
	}

    return 0;
}
