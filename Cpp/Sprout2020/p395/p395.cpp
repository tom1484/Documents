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

#define inf 0x3f3f3f3f

const int maxn = 500;

int N;
int w[maxn][maxn];
int d[maxn][maxn];
int e[maxn];

void dijkstra(int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, t;

	cin >> N;
	FOR (i, 0, N) 
		FOR (j, 0, N) 
			cin >> w[i][j];

	FOR (i, 0, N)
		FOR (j, 0, N)
			d[i][j] = w[i][j];

	FOR (k, 0, N) {
		FOR (i, 0, N) {
			FOR (j, 0, N) {
				v = d[i][k] + d[k][j];
				if (v < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	FOR (i, 0, N) {
		memset(e, 0x3f3f3f3f, sizeof e);
		FOR (j, 0, N) {
			v = w[i][j] + w[j][i];
			if (v > 0) {
				e[i] = w[i][j] + w[j][i];
				break;
			}
		}
		dijkstra(i);

		e[i] = 0;
		cout << e[0] - d[i][0];
		FOR (j, 1, N)
			cout << ' ' << e[j] - d[i][j];
		cout << '\n';
	}

    return 0;
}


void dijkstra(int s) {
	
	priority_queue<pii> Q;
	Q.push(mp(e[s], s));

	int x, v;
	while (!Q.empty()) {
		x = Q.top().sd;
		v = Q.top().ft;
		Q.pop();

		if (v > e[x])
			continue;

		FOR (i, 0, N) {
			v = e[x] + w[x][i];
			if (v > d[s][i] && v < e[i]) {
				e[i] = v;
				Q.push(mp(v, i));
			}
			v = d[s][x] + w[x][i];
			if (v > d[s][i] && v < e[i]) {
				e[i] = v;
				Q.push(mp(v, i));
			}
		}
	}

}






