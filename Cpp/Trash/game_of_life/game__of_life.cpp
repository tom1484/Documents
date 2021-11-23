#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, M, Q;
int arr[301][30][30];

bool valid(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int calc(int a, int i, int j) {
	int r = 0;
	FOR (x, -1, 2)
		FOR (y, -1, 2)
			if (valid(i + x, j + x) && arr[a][i + x][j + x])
				r++;
	return r;
}

int main() {
	
	cin >> N >> M;
	FOR (i, 0, N)
		FOR (j, 0, M)
			cin >> arr[0][i][j];

	FOR (a, 1, 301) {
		FOR (i, 0, N)
			FOR (j, 0, M) {
				int n = calc(a - 1, i, j);
				if (arr[a][i][j] && (n == 2 || n == 3))
					arr[a][i][j] = 1;
				else if (n == 3)
					arr[a][i][j] = 1;
				else
					arr[a][i][j] = 0;
			}
	}

	cin >> Q;
	int z;
	FOR (q, 1, Q + 1) {
		cin >> z;
		FOR (i, 0, N) {
			FOR (j, 0, M)
				cout << arr[z][i][j] << ' ';
			cout << '\n';
		}
	}

	return 0;
}
