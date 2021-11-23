#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 1e5 + 5;
const int maxm = 3e5 + 5;

int T, N, M;
vector<int> G[maxn];
priority_queue<int, vector<int>, greater<int>> Q;
int cnt[maxn];
int ans[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> T;
    while (T--) {
        memset(G, 0, sizeof G);
        memset(cnt, 0, sizeof cnt);
        while (!Q.empty())
            Q.pop();
        cin >> N >> M;

        int a, b;
        FOR (i, 0, M) {
            cin >> a >> b;
            G[a].pb(b);
            cnt[b]++;
        }

        FOR (i, 0, N)
            if (!cnt[i])
                Q.push(i);

        int s, i = 0;
        while (!Q.empty()) {
            s = Q.top();
            Q.pop();
            ans[i++] = s;

            for (int x: G[s]) {
                cnt[x]--;
                if (!cnt[x])
                    Q.push(x);
            }
        }

        if (i == N) {
            FOR (i, 0, N)
                cout << ans[i] << " \n"[i == N - 1];
        }
        else
            cout << "QAQ\n";
    }

    return 0;
}
/**
2
3 3
0 1
1 2
0 2
3 3
0 1
1 2
2 0
**/
