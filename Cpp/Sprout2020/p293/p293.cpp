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

int T, N, M;
int a, b;

int ans = 0, ansv = 1e9;
vector<int> tree[maxn];

int dfs(int i, int prt) {
	
	int tot = 1, num, res = 0;

	for (int x: tree[i]) if (x != prt) {
		num = dfs(x, i);
		tot += num;
		res = max(res, num);
	}
	res = max(res, N-tot);

	if (res < ansv) {
		ans = i;
		ansv = res;
	} else if (res == ansv)
		ans = min(ans, i);
	
	/* cout << i << ' ' << tot << '\n'; */

	return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	while (T--) {
		ans = 0, ansv = 1e9;
		FOR (i, 0, N)
			tree[i].clear();

		cin >> N;
		FOR (i, 0, N-1) {
			cin >> a >> b;
			tree[a].pb(b);
			tree[b].pb(a);
		}

		dfs(0, -1);
		cout << ans << '\n';
	}

    return 0;
}
