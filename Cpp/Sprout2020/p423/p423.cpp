#include <bits/stdc++.h>
using namespace std;

#define uint __uint32_t
#define ll __int64_t
#define ull __uint64_t
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 2001;
const ull inf = 0x3f3f3f3f3f3f3f3f;

int N;
ull K;

string arr;
int dp[maxn][maxn];
ull cnt[maxn][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr >> K;
	N = arr.size();

	FOR (i, 0, N) {
		dp[i][i] = 0;
		cnt[i][i] = 1;
	}
	FOR (i, 0, N - 1) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 0;
			cnt[i][i + 1] = 1;
		}
		else {
			dp[i][i + 1] = 1;
			cnt[i][i + 1] = 2;
		}
	}

	int j;
	FOR (l, 3, N + 1)
		FOR (i, 0, N - l + 1) {
			j = i + l - 1;
			if (arr[i] == arr[j]) {
				dp[i][j] = dp[i + 1][j - 1];
				cnt[i][j] = cnt[i + 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				if (dp[i + 1][j] == dp[i][j - 1])
					cnt[i][j] = cnt[i + 1][j] + cnt[i][j - 1];
				else if (dp[i + 1][j] < dp[i][j - 1])
					cnt[i][j] = cnt[i + 1][j];
				else
					cnt[i][j] = cnt[i][j - 1];
				cnt[i][j] = min(cnt[i][j], inf);
			}
		}

	int i;
	i = 0, j = N - 1;
	string ans = "";
	while (K > 1 && i <= j) {
		if (arr[i] == arr[j]) {
			ans += arr[i];
			i++, j--;
		}
		else if (dp[i + 1][j] == dp[i][j - 1]) {
			if (arr[i] < arr[j]) {
				if (cnt[i + 1][j] >= K) {
					ans += arr[i];
					i++;
				}
				else {
					K -= cnt[i + 1][j];
					if (cnt[i][j - 1] < K)
						K = 0;
					ans += arr[j];
					j--;
				}
			}
			else {
				if (cnt[i][j - 1] >= K) {
					ans += arr[j];
					j--;
				}
				else {
					K -= cnt[i][j - 1];
					if (cnt[i + 1][j] < K)
						K = 0;
					ans += arr[i];
					i++;
				}
			}
		}
		else if (dp[i + 1][j] < dp[i][j - 1]) {
			if (cnt[i + 1][j] >= K) {
				ans += arr[i];
				i++;
			}
			else
				K = 0;
		}
		else {
			if (cnt[i][j - 1] >= K) {
				ans += arr[j];
				j--;
			}
			else
				K = 0;
		}
	}

	if (K != 1)
		cout << "NONE\n";
	else {
		while (i <= j) {
			if (arr[i] == arr[j]) {
				ans += arr[i];
				i++, j--;
			}
			else if (dp[i + 1][j] == dp[i][j - 1]) {
				if (arr[i] < arr[j]) {
					ans += arr[i];
					i++;
				}
				else {
					ans += arr[j];
					j--;
				}
			}
			else {
				if (dp[i + 1][j] < dp[i][j - 1]) {
					ans += arr[i];
					i++;
				}
				else {
					ans += arr[j];
					j--;
				}
			}
		}

		cout << ans;
		if (i - j == 1)
			RFOR (i, ans.size(), 0)
				cout << ans[i];
		else 
			RFOR (i, ans.size() - 1, 0)
				cout << ans[i];
		cout << '\n';
	}

    return 0;
}
