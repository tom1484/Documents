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

const int maxn = 1e5 + 5;

int N, M, tmp;
vector<int> G[maxn];
bool arr[maxn];
bool vis[maxn];
vector<int> D[2];
int L[2];

void dfs(int s, int p, int d) {
	if (vis[s])
		return ;
	vis[s] = true;
	
	if (arr[s])
		D[p].pb(d);

	bool ed = true;
	FOR (i, 0, G[s].size()) {
		if (s == tmp) {
			ed = false;
			dfs(G[s][i], i, d + 1);
		}
		else {
			ed = false;
			dfs(G[s][i], p, d + 1);
		}
	}

	if (ed)
		L[p] = d;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int a, b;
	FOR (i, 0, N - 1) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR (i, 0, M) {
		cin >> a;
		arr[a] = 1;
	}
	cin >> tmp;

	memset(vis, 0, sizeof vis);
	dfs(tmp, -1, 0);

	sort(D[0].begin(), D[0].end());
	sort(D[1].begin(), D[1].end());

	int ans;
	if (!D[0].empty() && !D[1].empty())
		ans = (D[0][0] + D[1][0] + 1) / 2;
	else if (!D[0].empty())
		ans = D[0][0] + L[1];
	else if (!D[1].empty())
		ans = D[1][0] + L[0];

	cout << ans << '\n';

    return 0;
}
