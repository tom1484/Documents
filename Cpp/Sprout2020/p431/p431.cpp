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

const int maxn = 2e5 + 5;

ll T, N, M, Q;
vector<pll> G1[maxn], G2[maxn];
ll D1[maxn], D2[maxn];

void dijkstra(ll s, ll *D, vector<pll> *G) {
    priority_queue<pll, vector<pll>, greater<pll>> Q;

    D[s] = 0;
    Q.push(mp(0, s));
    while (!Q.empty()) {
        pll p = Q.top();
        Q.pop();
        s = p.sd;
        
		if (p.ft > D[s])
            continue;
        
		for (pll t: G[s]) {
            if (D[s] + t.sd < D[t.ft]) {
                D[t.ft] = D[s] + t.sd;
                Q.push(mp(D[t.ft], t.ft));
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    memset(G1, 0, sizeof G1);
    memset(G2, 0, sizeof G2);
    cin >> N >> M >> Q;

    ll a, b, w;
    FOR (i, 0, M) {
        cin >> a >> b >> w;
        G1[a].pb(mp(b, w));
        G2[b].pb(mp(a, w));
    }

    memset(D1, 0x3f3f3f3f, sizeof D1);
    memset(D2, 0x3f3f3f3f, sizeof D2);
    dijkstra(1, D1, G1);
    dijkstra(N, D2, G2);

    FOR (i, 0, Q) {
        cin >> a >> b;
        cout << min(D1[N], D1[a] + 1 + D2[b]) << '\n';
    }

    return 0;
}
/**
5 8 4
1 1 1000000000
2 1 3
1 3 5
1 4 9
4 5 8
5 4 2
3 4 3
4 5 1
2 2
1 5
1 4
3 4
**/
