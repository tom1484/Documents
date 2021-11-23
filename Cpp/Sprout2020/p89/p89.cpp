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

const int maxn = 10005;

int N;
pii arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N) {
		FOR (i, 0, N)
			cin >> arr[i].sd >> arr[i].ft;
		sort(arr, arr+N);

		int ans = 0, cnt = 0;
		RFOR (i, N-1, -1) {
			/* cout << arr[i].ft << ' '; */
			ans = max(ans, cnt+arr[i].sd+arr[i].ft);
			cnt += arr[i].sd;
		}
		cout << ans << '\n';

		cin >> N;
	}

    return 0;
}
