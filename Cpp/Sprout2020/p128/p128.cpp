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

int arr[1024][1024];

void solve(int N) {
	
	int n = 1;
	arr[0][0] = 1;
	
	while (n < N) {
		FOR (i, 0, n)
			FOR (j, 0, n) {
				arr[n + i][n + j] = arr[i][j];
				arr[n + i][j] = arr[i][j] + 2 * n;
				arr[i][n + j] = arr[i][j] + 2 * n - (i == j);
			}
		n *= 2;
	}

	FOR (i, 0, N) 
		FOR (j, 0, N)
			Report(arr[i][j]);

}
