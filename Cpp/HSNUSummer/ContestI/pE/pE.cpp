#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 500005;

ll N, T;

ll s[maxn], e[maxn];
ll dp[2][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;

	FOR (i, 0, N - 1)
		cin >> s[i];
	FOR (i, 0, N - 1)
		cin >> e[i];

	dp[0][0] = 0;
	dp[1][0] = 1e9;

	FOR (i, 1, N) {
		dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + s[i - 1];
		dp[1][i] = min(dp[0][i - 1] + T, dp[1][i - 1]) + e[i - 1];
	}

	FOR (i, 0, N)
		cout << min(dp[0][i], dp[1][i]) << ' ';
	cout << '\n';

    return 0;
}
