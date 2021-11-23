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

const int maxn = 2e5 + 1;

int T;

int N;
int arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i];

		ll ans = 0;
		FOR (i, 1, N) {
			ans += arr[i];
			arr[i] *= -1;
			i++;
		}

		ll oMin = 1e9, eMin = 1e9;
		ll sum = 0, add = -1000000;
		FOR (i, 0, N) {
			sum += arr[i];
			if (i % 2) {
				eMin = min(eMin, sum);
				add = max(add, sum - eMin);
				cout << add << ' ';
			}
			else {
				oMin = min(oMin, sum);
				add = max(add, sum - oMin);
				cout << add << ' ';
			}
		}
		cout << '\n';

		cout << ans + add << '\n';
	}

    return 0;
}
