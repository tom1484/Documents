/*
ID: angelus6
TASK: castle
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
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
ofstream fout ("castle.out");
ifstream fin ("castle.in");

const int maxn = 50;
int n, m;
int arr[maxn*2+1][maxn*2+1] = {};
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

vector<int> flood;

int floodfill(int i, int j, int id) {
	//cout << arr[i][j] << ' ';
	int res = 0;
	if ((i&1) && (j&1))
		res++;
	arr[i][j] = id;
	FOR (d, 0, 4) {
		int x = i+dir[d][0], y = j+dir[d][1];
		if (x >= 0 && x < n*2+1 && y >= 0 && y < m*2+1)
			if (arr[x][y] != -1 && arr[x][y] == 0)
				res += floodfill(x, y, id);
	}
	return res;
}

int main() {

	cin >> m >> n;
	FOR (i, 0, n)
		FOR (j, 0, m) {
			int t, x = i*2+1, y = j*2+1;
			cin >> t;
			for (int s = 0; t; s++, t >>= 1) {
				if (t&1) {
					arr[x + dir[s][0]][y + dir[s][1]] = -1;
					arr[x + dir[s][0] + dir[(s+1)&3][0]][y + dir[s][1] + dir[(s+1)&3][1]] = -1;
					arr[x + dir[s][0] + dir[(s-1)&3][0]][y + dir[s][1] + dir[(s-1)&3][1]] = -1;
				}			
			}
		}

	int t = 0;
	FOR (i, 0, n)
		FOR (j, 0, m)
			if (arr[i*2+1][j*2+1] == 0) {
				flood.pb(floodfill(i*2+1, j*2+1, flood.size()+1));
				t = max(t, flood.back());
			}

//	for (int x: flood)
//		cout << x << ' ';
//	cout << '\n';
//	FOR (i, 0, n*2+1) {
//		FOR (j, 0, m*2+1)
//			cout << setw(4) << arr[i][j];
//		cout << '\n';
//	}

	cout << flood.size() << '\n';
	cout << t << '\n';

	int rx, ry, maxf = 0;
	FOR (i, 0, n*2+1)
		FOR (j, 0, m*2+1) {
			if ((i&1) && !(j&1) &&  j > 0 && j < m*2) 
				if (arr[i][j-1] != arr[i][j+1]) {
					int t = flood[arr[i][j-1]-1]+flood[arr[i][j+1]-1];
					if (maxf < t || (maxf == t && (ry > j || (ry == j && rx < i)))) {
						maxf = t;
						rx = i, ry = j;
					}
				}
			if (!(i&1) && (j&1) &&  i > 0 && i < n*2)
				if (arr[i-1][j] != arr[i+1][j]) {
					int t = flood[arr[i-1][j]-1]+flood[arr[i+1][j]-1];
					if (maxf < t || (maxf == t && (ry > j || (ry == j && rx < i)))) {
						maxf = t;
						rx = i, ry = j;
					}
				}
		}
	cout << maxf << '\n';

	if (ry > 0 && !(ry&1))
		cout << rx/2+1 << ' ' << ry/2 << " E\n";
	else if (rx < n*2 && !(rx&1))
		cout << rx/2+1 << ' ' << ry/2+1 << " N\n";

	return 0;
}
