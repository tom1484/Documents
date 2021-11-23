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

int N, M;

int prt[maxn], sz[maxn];
priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> E;

int F(int x) {
    return x == prt[x] ? x : prt[x] = F(prt[x]);
}

void U(int x, int y) {
    if (sz[F(x)] > sz[F(y)])
        swap(x, y);
    prt[prt[x]] = prt[y];
    sz[prt[y]] += sz[prt[x]];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	FOR (i, 1, N + 1)
        prt[i] = i, sz[i] = 1;

    ll ans = 0, w;
    int a, b;
    FOR (i, 0, M) {
        cin >> a >> b >> w;
        E.push(mp(w, mp(a, b)));
    }

    while (!E.empty()) {
        pair<ll, pii> p = E.top();
        E.pop();
        w = p.ft;
        a = p.sd.ft, b = p.sd.sd;
        if (F(a) != F(b)) {
            ans += w;
            U(a, b);
        }
    }
    cout << ans << '\n';

    return 0;
}
/**
3 3
1 2 3
2 3 4
3 1 5
**/
