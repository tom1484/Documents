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

const int maxn =101;

int T, N;
int arr[maxn], pre[maxn][maxn], dp[maxn][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i];

		FOR (i, 0, N) {
			pre[i][i] = arr[i];
			dp[i][i] = 0;
			FOR (j, i + 1, N)
				pre[i][j] = pre[i][j - 1] + arr[j];
		}

		FOR (l, 1, N)
			FOR (i, 0, N) {
				int r = i + l;
				if (r >= N)
					break;
				dp[i][r] = 1e9;
				FOR (j, i, r)
					dp[i][r] = min(dp[i][r], pre[i][r] + dp[i][j] + dp[j + 1][r]);
			}
		
		cout << dp[0][N - 1] << '\n';
	}

    return 0;
}
