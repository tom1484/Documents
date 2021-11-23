#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 105;

ll T, N, M, S, E, F;
vector<pll> G[maxn];
ll dp[maxn];

ll dijkstra() {
    priority_queue<pll, vector<pll>, greater<pll>> Q;

    dp[S] = 0;
    Q.push(mp(0, S));
    while (!Q.empty()) {
        pll p = Q.top();
        Q.pop();
        ll s = p.sd;
        if (p.ft > dp[s])
            continue;
        for (pll t: G[s]) {
            if (dp[s] + t.sd < dp[t.ft]) {
                dp[t.ft] = dp[s] + t.sd;
                Q.push(mp(dp[t.ft], t.ft));
            }
        }
    }

    return dp[E];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> T;
    while (T--) {
        memset(G, 0, sizeof G);
        cin >> N >> M >> S >> E >> F;
        S--, E--;

        ll a, b, c, d, _c, w;
        FOR (i, 0, M) {
            cin >> a >> b >> c >> d >> _c;
            a--, b--;
            if (F > d)
                w = d * c + (F - d) * _c;
            else
                w = F * c;
            G[a].pb(mp(b, w));
        }

        memset(dp, 0x3f3f3f3f3f3f3f3f, sizeof dp);
        cout << dijkstra() << '\n';
    }

    return 0;
}
/**
3
4 4 1 4 1
1 2 1 1 1
2 4 5 1 3
1 3 1 1 1
3 4 6 1 1
4 4 1 4 2
1 2 1 1 1
2 4 5 1 3
1 3 1 1 1
3 4 6 1 1
2 1 1 2 999999999
1 2 50216 1000 50216
**/
