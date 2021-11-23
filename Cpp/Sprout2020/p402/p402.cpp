#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

struct Vec {
	ll x, y;
	bool operator<(Vec p) {
		return x == p.x ? y < p.y : x < p.x;
	}
	ll cross(Vec p) {
		return x * p.y - y * p.x;
	}
};

const int maxn = 1e5 + 1;

int T, N;
Vec arr[maxn];
Vec conv[maxn];

ll cross(Vec v1, Vec v2, Vec v) {
	ll x1 = v1.x - v.x;
	ll y1 = v1.y - v.y;
	ll x2 = v2.x - v.x;
	ll y2 = v2.y - v.y;
	return x1 * y2 - y1 * x2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i].x >> arr[i].y;
		sort(arr, arr + N);

		int m = 0;
		FOR (i, 0, N) {
			while (m >= 2 && cross(arr[i], conv[m - 1], conv[m - 2]) >= 0)
				m--;
			conv[m++] = arr[i];
		}

		int t = m + 1;
		RFOR (i, N - 1, 0) {
			while (m >= t && cross(arr[i], conv[m - 1], conv[m - 2]) >= 0)
				m--;
			conv[m++] = arr[i];
		}

		ll res = 0;
		FOR (i, 0, m - 1) 
			res += conv[i].x * conv[i + 1].y - conv[i].y * conv[i + 1].x;
	
		cout << res / 2;
		if (res % 2)
			cout << ".5\n";
		else
			cout << ".0\n";
	}

    return 0;
}









