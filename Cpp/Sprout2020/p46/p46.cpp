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

int cidx[27];
char clr[8] = {'0', 'R', 'Y', 'O', 'B', 'P', 'G', 'D'};

int idx(char c) {
	return cidx[c-'A'+1];
}

struct Pos {
	int x, y;
	Pos(int x, int y): x(x), y(y) {}
	Pos() {}
};

struct Color {
	bool r, y, b;
	
	Color() {
		r = y = b = false;
	}

	Color(int i) {
		if (i == 1) 
			r = true, y = b = false;
		if (i == 2) 
			y = true, r = b = false;
		if (i == 4) 
			b = true, r = y = false;
	}

	void operator+=(Color t) {
		r |= t.r;
		y |= t.y;
		b |= t.b;
	}

	int idx() {
		return int(r)+int(y)*2+int(b)*4;
	}
};

int T, N;
queue<Pos> Q[3], mod[3];
Color arr[1005][1005];
bool vis[3][1005][1005];
int ans[8], area[8];

inline bool valid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

inline void update() {
	FOR (i, 1, 8)
		ans[i] = max(ans[i], area[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	FOR (i, 1, 8)
		cidx[clr[i]-'A'+1] = i;
	char ch, query;
	int x, y;

	cin >> T;
	while (T--) {
		int cnt = 0;
		FOR (i, 0, 3) {
			while (!Q[i].empty())
				Q[i].pop();
			while (!mod[i].empty())
				mod[i].pop();
		}
		memset(ans, 0, sizeof ans);
		memset(area, 0, sizeof area);
		memset(arr, 0, sizeof arr);
		memset(vis, 0, sizeof vis);

		cin >> N;
		FOR (i, 0, 3) {
			cin >> ch >> x >> y;
			if (ch == 'R') {
				Q[0].push(Pos(x, y));
				vis[0][x][y] = true;
			}
			if (ch == 'Y') {
				Q[1].push(Pos(x, y));
				vis[1][x][y] = true;
			}
			if (ch == 'B') {
				Q[2].push(Pos(x, y));
				vis[2][x][y] = true;
			}
		}
		cin >> query;

		FOR (t, 0, N+1) {
			FOR (i, 0, 3) {
				int step = Q[i].size();
				while (step--) {
					mod[i].push(Q[i].front());
					x = Q[i].front().x;
					y = Q[i].front().y;
					Q[i].pop();
					
					FOR (j, -1, 2)
						FOR (k, -1, 2) {
							int a = x+j, b = y+k;
							if (valid(a, b) && !vis[i][a][b]) {
								vis[i][a][b] = true;
								Q[i].push(Pos(a, b));
							}
						}
				}
			}

			FOR (i, 0, 3) {
				while (!mod[i].empty()) {
					x = mod[i].front().x;
					y = mod[i].front().y;
					mod[i].pop();
					
					area[arr[x][y].idx()]--;
					arr[x][y] += Color((1<<i));
					area[arr[x][y].idx()]++;
				}
			}
			update();
			
			if (area[7] == N*N)
				break;
		}
		cout << ans[idx(query)];
		cout << '\n';
	}

    return 0;
}
