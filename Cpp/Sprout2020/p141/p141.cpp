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

const int maxn = 1e5 + 1;

int T, N;
int arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i];

		arr[1] = arr[1];
		arr[2] = arr[0] + arr[2];
		FOR (i, 3, N)
			arr[i] += max(arr[i - 2], arr[i - 3]);

		int ans = 0;
		FOR (i, 0, N)
			ans = max(arr[i], ans);
		
		cout << ans << '\n';
	}

    return 0;
}
