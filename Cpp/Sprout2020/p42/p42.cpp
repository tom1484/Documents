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

const int maxn = 1005;

int T, N, M;
bool arr[maxn][maxn];
int dir[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool valid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int floodfill(int x, int y) {
	
	int res = 1;
	queue<pii> Q;

	Q.push(mp(x, y));
	arr[x][y] = false;
	while (!Q.empty()) {
		res++;
		x = Q.front().ft;
		y = Q.front().sd;
		Q.pop();
		FOR (d, 0, 4) {
			int i = x+dir[d][0];
			int j = y+dir[d][1];
			if (valid(i, j) && arr[i][j]) {
				arr[i][j] = false;
				Q.push(mp(i, j));
			}	
		}
	}

	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	char t;

	cin >> T;
	while (T--) {
		cin >> N >> M;
		FOR (i, 0, N)
			FOR (j, 0, M) {
				cin >> t;
				arr[i][j] = t == '.';
			}

		int ans = 0;
		FOR (i, 0, N)
			FOR (j, 0, M)
			if (arr[i][j]) {
				ans++;
				floodfill(i, j);
			}
		cout << ans << '\n';
	}

    return 0;
}
