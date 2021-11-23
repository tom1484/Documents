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

int ans;
int N, M, x, y, sx, sy;
char c;
string str;
int arr[105][105];
int dis[105][105] = {};
int dir[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void floodfill() {
	
	queue<pii> Q;
	Q.push(mp(sx, sy));
	arr[sx][sy] = false;
	dis[sx][sy] = 0;
	while (!Q.empty()) {
		x = Q.front().ft;
		y = Q.front().sd;
		Q.pop();
		FOR (d, 0, 4) {
			int i = x+dir[d][0];
			int j = y+dir[d][1];
			if (arr[i][j]) {
				dis[i][j] = dis[x][y]+1;
				if (arr[i][j] == 2)
					ans = min(ans, dis[i][j]);
				arr[i][j] = false;
				Q.push(mp(i, j));
			}
		}
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	while (N) {
		FOR (i, 0, N) {
			cin >> str;
			M = str.size();
			FOR (j, 0, M) {
				c = str[j];
				arr[i][j] = !(c == '#');
				if (c == '@')
					arr[i][j] = 2;
				if (c == 'K')
					sx = i, sy = j;
			}
		}

		ans = 10000;
		floodfill();
		if (ans != 10000)
			cout << ans << '\n';
		else
			cout << "= =\"\n";

		cin >> N;
	}

    return 0;
}
