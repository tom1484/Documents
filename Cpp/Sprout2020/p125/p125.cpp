#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a-1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const ll maxn = 1000005;
const ll MOD = 10000019;

ll N;
ll ans = 0;
ll arr[maxn] = {}, tmp[maxn] = {};

ll mod(ll x) {
	return x % MOD;
}

void solve(ll lt, ll rt) {
	
	if (rt - lt <= 1)
		return ;

	ll mid = (lt + rt) / 2;
	solve(lt, mid);
	solve(mid, rt);

	ll p = lt, q = mid, cnt = lt;
	while (cnt < rt) {
		if (q == rt || (p < mid && arr[p] <= arr[q])) {
			ans = mod(ans + arr[p] * (q - mid));
			tmp[cnt++] = arr[p++];
		}
		else {
			ans = mod(ans + arr[q] * (mid - p));
			tmp[cnt++] = arr[q++];
		}
	}

	FOR (i, lt, rt)
		arr[i] = tmp[i];
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	FOR (i, 0, N)
		cin >> arr[i];
	solve(0, N);
	cout << ans << '\n';

    return 0;
}
