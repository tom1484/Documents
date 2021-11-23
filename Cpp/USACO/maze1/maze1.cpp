/*
ID: angelus6
TASK: maze1
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("maze1.in");
ofstream fout("maze1.out");

int w, h;
bool arr[201][77];
bool vis[3800] = {};
queue<int> q;
int path[2][3800];
vector<int> edges[3800];
int dir[4][2] = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool valid(int x, int y) {
	return arr[x][y] && x > 0 && x < h*2 && y > 0 && y < w*2;
}

int getIdx(int x, int y) {
	return x*w+y;
}

pii getPos(int idx) {
	return make_pair(idx/w, idx%w);
}

int main() {

	cin >> w >> h;

	string s;
	getline(cin, s);
	FOR (i, 0, h*2+1) {
		getline(cin, s);
		FOR (j, 0, w*2+1) {
			arr[i][j] = j < s.size() ? (s[j] == ' ') : true;
		}
	}

	int p[2] = {-1, -1};
	FOR (i, 0, h*2+1)
		FOR (j, 0, w*2+1) {
			if (i%2 && j%2) {
				FOR (d, 0, 4) {
					int x1 = i/2, y1 = j/2;
					int x2 = x1+dir[d][0], y2 = y1+dir[d][1];
					int idx1 = getIdx(x1, y1), idx2 = getIdx(x2, y2);
					if (valid(i+dir[d][0], j+dir[d][1])) 
						edges[idx1].pb(idx2);
				}
			}
			if (arr[i][j]) {
				if (i == 0)
					p[p[0] != -1] = getIdx(0, j/2);
				else if (j == 0)
					p[p[0] != -1] = getIdx(i/2, 0);
				else if (i == h*2)
					p[p[0] != -1] = getIdx(h-1, j/2);
				else if (j == w*2)
					p[p[0] != -1] = getIdx(i/2, w-1);
			}
		}

	FOR (i, 0, 2) {
		memset(vis, 0, sizeof vis);
		q.push(p[i]);
		path[i][p[i]] = 0;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (vis[now])
				continue;
			vis[now] = true;
			for (int to: edges[now]) {
				q.push(to);
				if (!vis[to])
					path[i][to] = path[i][now]+1;
			}
		}
	}

	int ans = 0;
	FOR (i, 0, w*h)
		ans = max(min(path[0][i], path[1][i]), ans);
	cout << ans+1 << '\n';

	return 0;
}
