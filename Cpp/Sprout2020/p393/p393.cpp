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

const int maxn = 2001;

int N, M, S, E;

bool arr[maxn * maxn];
int dp[maxn * maxn];
priority_queue<pii, vector<pii>, greater<pii>> Q;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

int toId(int i, int j) {
    return i * M + j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N >> M;

    char c;
    FOR (i, 0, N) {
        FOR (j, 0, M) {
            cin >> c;
            arr[toId(i, j)] = c == '.';
        }
    }

    int a, b;
    cin >> a >> b;
    S = toId(a - 1, b - 1);
    cin >> a >> b;
    E = toId(a - 1, b - 1);

    memset(dp, 0x3f3f3f3f, sizeof dp);
    int s, t, x, y;

    dp[S] = 0;
    Q.push(mp(0, S));
    while (!Q.empty()) {
        pii p = Q.top();
        Q.pop();
        s = p.sd;
        if (p.ft > dp[s])
            continue;

        x = s / M, y = s % M;
        FOR (d, 0, 4) {
            if (valid(x + dir[d][0], y + dir[d][1])) {
                t = toId(x + dir[d][0], y + dir[d][1]);
                if (dp[s] + arr[s] < dp[t]) {
                    dp[t] = dp[s] + arr[s];
                    Q.push(mp(dp[t], t));
                }
            }
        }
    }

    cout << dp[E] << '\n';

    return 0;
}
/**
6 6
#.####
#.#..#
#.#..#
#.##.#
#....#
######
1 1 4 4

4 5
#..##
.##..
#..##
..#.#
1 1 4 5
**/
