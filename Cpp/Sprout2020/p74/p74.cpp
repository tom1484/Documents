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

const int maxn = 1000005;

ll T, N;
ll arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		int t, ans = 0, last = -1, s = true;
		FOR (i, 0, N) {
			cin >> t;
			if (s && t > last) {
				ans++;
				s = !s;
			}
			else if (!s && t < last) {
				ans++;
				s = !s;
			}
			last = t;
		}
		ans -= !(ans%2);
		cout << ans << '\n';
	}

    return 0;
}
