#include <iostream>
#include <algorithm>
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

struct Point {
	int x, y;

	bool operator<(Point &p) {
		if (x == p.x)
			return y < p.y;
		return x < p.x;
	}
};

const ll inf = (1ll << 62) + ((1ll << 62) - 1);
const int maxn = 2e5;

int N;
Point arr[maxn];
Point tmp[maxn];

ll solve(int, int);
ll dis(int, int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	FOR (i, 0, N)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr + N);
	cout << solve(0, N) << '\n';

    return 0;
}

ll dis(Point *A, int i, int j) {

	ll dx = A[i].x - A[j].x;
	ll dy = A[i].y - A[j].y;
	
	return dx * dx + dy * dy;
}

ll solve(int l, int r) {

	if (r - l <= 1)
		return inf;

	int m = (l + r) / 2;
	ll mx = arr[m].x;
	ll res = min(solve(l, m), solve(m, r));

	int s = l, t = m;
	FOR (i, l, r) {
		if (s == m)
			tmp[i] = arr[t++];
		else if (t == r)
			tmp[i] = arr[s++];
		else {
			if (arr[s].y < arr[t].y)
				tmp[i] = arr[s++];
			else
				tmp[i] = arr[t++];
		}
	}
	FOR (i, l, r)
		arr[i] = tmp[i];

	ll d;
	int p = 0;
	FOR (i, l, r) {
		d = arr[i].x - mx;
		if (d * d < res)
			tmp[p++] = arr[i];
	}

	int j;
	FOR (i, 0, p) {
		j = i - 1;
		while (j >= 0) {
			d = tmp[i].y - tmp[j].y;
			if (d * d >= res)
				break;
			res = min(res, dis(tmp, i, j));
			j--;
		}
	}

	return res;
}



