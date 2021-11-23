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

int num[7], ans, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		FOR (i, 1, 7)
			cin >> num[i];
		FOR (i, 1, 7) {
			if (num[i])	break;
			if (i == 6) return 0;
		}

		ans = num[6]+num[5]+num[4];
		num[1] -= min(num[1], num[5]*11);
		if (num[2] < num[4]*5)
			num[1] -= min(num[1], (num[4]*5-num[2])*4);
		num[2] -= min(num[2], num[4]*5);
		ans += num[2]/9;
		num[2] %= 9;
		ans += num[3]/4;
		num[3] %= 4;
		if (num[3]) ans++;
		if (num[3] == 1) {
			t = min(num[2], 5);
			num[2] -= t;
			num[1] -= min(num[1], 27-t*4);
		}
		if (num[3] == 2) {
			t = min(num[2], 3);
			num[2] -= t;
			num[1] -= min(num[1], 18-t*4);
		}
		if (num[3] == 3) {
			t = min(num[2], 1);
			num[2] -= t;
			num[1] -= min(num[1], 9-t*4);
		}
		if (num[2]) {
			ans++;
			num[1] -= 36-num[2]*4;
		}
		if (num[1] > 0)
			ans += num[1]/36+(num[1]%36 > 0);
		cout << ans << '\n';
	}

    return 0;
}
