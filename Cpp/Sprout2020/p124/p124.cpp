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

bool arr[1030][1030];

/* void Report(int x1, int y1, int x2, int y2, int x3, int y3) { */
	/* cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << '\n'; */
	/* FOR (i, 0, 16) { */
		/* FOR (j, 0, 16) */
			/* cout << arr[i][j]; */
		/* cout << '\n'; */
	/* } */
	/* cout << '\n'; */
/* } */

void dfs(int L1, int R1, int L2, int R2) {

	int x, y;
	for (x = L1; x < R1; x++) {
		for (y = L2; y < R2; y++) 
			if (arr[x][y]) break;
		if (y != R2) break;
	}
	
	/* cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << '\n'; */

	int M1 = (L1+R1)/2, M2 = (L2+R2)/2;
	if (x < M1 && y < M2) {
		arr[M1-1][M2] = arr[M1][M2-1] = arr[M1][M2] = 1;
		Report(M1, M2+1, M1+1, M2, M1+1, M2+1);
	}
	else if (x < M1 && y >= M2) {
		arr[M1-1][M2-1] = arr[M1][M2-1] = arr[M1][M2] = 1;
		Report(M1, M2, M1+1, M2, M1+1, M2+1);
	}
	else if (x >= M1 && y < M2) {
		arr[M1-1][M2-1] = arr[M1-1][M2] = arr[M1][M2] = 1;
		Report(M1, M2, M1, M2+1, M1+1, M2+1);
	}
	else if (x >= M1 && y >= M2) {
		arr[M1-1][M2-1] = arr[M1-1][M2] = arr[M1][M2-1] = 1;
		Report(M1, M2, M1, M2+1, M1+1, M2);
	}

	if (R1-L1 > 2) {
		dfs(L1, M1, L2, M2);
		dfs(M1, R1, L2, M2);
		dfs(L1, M1, M2, R2);
		dfs(M1, R1, M2, R2);
	}
}

void solve(int N, int X, int Y) {
	memset(arr, 0, sizeof arr);
	arr[X-1][Y-1] = 1;
	dfs(0, N, 0, N);
}

/* int main() { */
	/* ios::sync_with_stdio(false); */
	/* cin.tie(NULL); */

	/* solve(16, 6, 3); */

    /* return 0; */
/* } */
