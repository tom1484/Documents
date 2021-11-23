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

const int maxn = 1000005;

int N;
int arr[maxn];
bool vis[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	FOR (i, 1, N + 1) {
		cin >> arr[i];
	}
	FOR (i, 1, N + 1)
		vis[i] = false;

	int ans = 0;

	for (int i = 1; i <= N; i ++) {
		if (vis[i])
			continue;

		int cnt = -1;
		int p = arr[i];
		while (!vis[p]) {
			vis[p] = true;
			p = arr[p];
			cnt++;
		}

		ans += cnt;
	}

	cout << ans << '\n';

    return 0;
}
