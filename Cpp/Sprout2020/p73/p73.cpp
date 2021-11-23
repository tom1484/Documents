#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

const ll maxn = 100005;
const ll maxc = 10000;

ll T, N, M;
ll arr[maxn];

bool f(ll x) {

	ll p = 0, cnt;
	FOR (i, 0, M) {
		cnt = 0;
		while (p <= N-M+i && cnt+arr[p] <= x)
			cnt += arr[p], p++;
	}
	
	return p == N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		FOR (i, 0, N)
			cin >> arr[i];

		ll l = 0, r = maxc*N;
		for (ll i = __lg(r)+1; i >= 0; i--)
			if (!f(l+(1ll<<i)))
				l += 1ll<<i;
		cout << l+1 << '\n';
	}


    return 0;
}
