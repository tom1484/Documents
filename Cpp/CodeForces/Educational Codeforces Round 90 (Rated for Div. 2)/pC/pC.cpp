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

int T;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> str;
		int m = 0, s = 0;
		ll ans = 0;
		FOR (i, 0, str.size()) {
			s += (str[i] == '+' ? 1 : -1);
			if (s < m) {
				ans += (ll) (m - s) * (i + 1);
				m = s;
			}
		}
		if (s >= m)
			ans += str.size();
		cout << ans << '\n';
	}

    return 0;
}
