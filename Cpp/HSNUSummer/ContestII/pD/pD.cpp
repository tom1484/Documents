#include <bits/stdc++.h>
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

const int maxn = 200005;

int N;

ll arr[maxn];
int ans[maxn];

ll bit[maxn];

void add(int p, int v) {
	for (; p <= N; p += p & (-p))
		bit[p] += v;
}

int query(int p) {
	ll ans = 0;
	for (; p >= 1; p -= p & (-p))
		ans += bit[p];
	
	return ans;
}

int calc(ll v) {
	double d = (-1 + sqrt(1 + 8 * v)) / 2.0;
	int ans = floor(d);
	if (d - ans != 0)
		return -1;

	return ans + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	FOR (i, 0, N)
		cin >> arr[i];

	/* FOR (i, 0, N) */
		/* cout << N - i << ' '; */
	/* cout << '\n'; */

	/* FOR (i, 0, N) */
		/* cout << i + 1 << ' '; */
	/* cout << '\n'; */

	/* FOR (i, 0, N) */
		/* bit[i] = 0; */

	/* ll s; */
	/* int r; */

	/* RFOR (i, N, 0) { */
	/* 	FOR (j, 1, N + 1) { */
	/* 		s = query(j); */
	/* 		r = calc(arr[i] + s); */
	/* 		/1* cout << r << ' '; *1/ */
	/* 		if (r > 0 && r == j) { */
	/* 			ans[i] = r; */
	/* 			break; */
	/* 		} */
	/* 	} */
	/* 	/1* cout << '\n'; *1/ */
	/* 	add(ans[i], ans[i]); */
	/* } */

	/* FOR (i, 0, N) */
	/* 	cout << ans[i] << ' '; */
	/* cout << '\n'; */

    return 0;
}
