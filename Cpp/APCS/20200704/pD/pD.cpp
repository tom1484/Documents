#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 1000;
const int maxm = 80;

struct Node {
	vector<int> ch;
	int rna[maxm];
};

int N, M, D = 0;
Node arr[maxn] = {};
int dp[maxn][4];

void solve(int s, int m) {

	memset(dp[s], 0, sizeof dp[s]);
	
	if (!arr[s].ch.size())
		return ;

	for (int c: arr[s].ch)
		solve(c, m);

	FOR (j, 0, 4) {
		for (int c: arr[s].ch) {
			int minV = 1e9;
			if (arr[c].rna[m] == -1)
				FOR (k, 0, 4)
					minV = min(minV, dp[c][k] + (j != k));
			else
				minV = dp[c][arr[c].rna[m]] + (j != arr[c].rna[m]);
			dp[s][j] += minV;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int toInt[26];
	toInt['A' - 'A'] = 0;
	toInt['U' - 'A'] = 1;
	toInt['G' - 'A'] = 2;
	toInt['C' - 'A'] = 3;

	cin >> N >> M;

	int a, b;
	string str;
	FOR (i, 0, N) {
		cin >> a >> b >> str;
		a--, b--;
		
		FOR (j, 0, M)
			arr[a].rna[j] = (str[j] == '@' ? -1 : toInt[str[j] - 'A']);

		if (b != a)
			arr[b].ch.pb(a);
	}

	int ans = 0;
	FOR (i, 0, M) {
		solve(0, i);
		/* FOR (j, 0, N) { */
			/* cout << j + 1 << ": "; */
			/* FOR (k, 0, 4) */
				/* cout << dp[j][k] << ' '; */
			/* cout << '\n'; */
		/* } */
		if (arr[0].rna[i] == -1)
			ans += *min_element(dp[0], dp[0] + 4);
		else
			ans += dp[0][arr[0].rna[i]];
	}

	cout << ans << '\n';

    return 0;
}
