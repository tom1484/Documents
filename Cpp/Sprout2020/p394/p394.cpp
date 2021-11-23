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

const int maxn = 500;
const int inf = 1e6;

int N;
int w[maxn][maxn];
int dis[maxn][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	FOR (i, 0, N)
		FOR (j, 0, N) {
			dis[i][j] = (i == j ? 0 : inf);
			cin >> w[i][j];
			if (w[i][j] < 0)
				w[i][j] = inf;
		}

	FOR (n, 0, N) {
		FOR (i, 0, n) {
			FOR (j, 0, n) {
				dis[i][n] = min(dis[i][n], dis[i][j] + w[j][n]);
				dis[n][i] = min(dis[n][i], w[n][j] + dis[j][i]);
			}
		}

		FOR (i, 0, n)
			FOR (j, 0, n)
				dis[i][j] = min(dis[i][j], dis[i][n] + dis[n][j]);
		
		int ans = 0;
		FOR (i, 0, n + 1)
			FOR (j, 0, n + 1)
				ans = max(ans, dis[i][j]);
		cout << (ans < inf ? ans : -1) << (n < N - 1 ? " " : "");
	}
	cout << '\n';

    return 0;
}
