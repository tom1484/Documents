#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
/* #define ull __uint128 */
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

/* random_device rd; */
/* default_random_engine gen = std::default_random_engine(rd()); */
/* uniform_int_distribution<ll> dis(1, 1e6); */

const int MOD = 1e9 + 7;

ll mod(ll x) {
	return (x + MOD) % MOD;
}

const int maxn = 5e5 + 1;

int N, K, M;
int arr[maxn];
int cnt[maxn];
ll pre[maxn];
ll val[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> M;
	mt19937 rng(time(0));
	FOR (i, 1, N) 
		cin >> arr[i];

	memset(val, 0, sizeof val);
	FOR (i, 1, N)
		val[i] = mod(rng());

	pre[0] = 0;
	memset(cnt, 0, sizeof cnt);
	FOR (i, 1, N) {
		cnt[arr[i]]++;
		if (cnt[arr[i]] % K == 0)
			pre[i] = pre[i - 1] - val[arr[i]] * (K - 1);
		else
			pre[i] = pre[i - 1] + val[arr[i]];
		pre[i] = mod(pre[i]);
	}

	int l, r;
	FOR (i, 1, M) {
		cin >> l >> r;
		cout << (mod(pre[r] - pre[l - 1]) == 0);
	}
	cout << '\n';

    return 0;
}





