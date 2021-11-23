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

const ll maxn = 10005;

ll T, N, K;
ll ori[maxn], pot[maxn], arr[maxn], tar[maxn];

bool cmp(ll x, ll y) {
	return x > y;
}

bool f(ll m) {
	
	FOR (i, 0, N)
		arr[i] = ori[i]+pot[i]*m;
	sort(arr, arr+N, cmp);
	
	ll tot = 0, p = 0, cnt = 0;
	FOR (i, 0, N) {
		while (p <= N && arr[p] > tar[i]) 
			p++, tot++;
		if (tot)
			tot--, cnt++;
	}

	return cnt >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	ll a, b, l, r, s;
	while (T--) {
		cin >> N >> K;
		FOR (i, 0, N)
			cin >> ori[i] >> pot[i];

		l = r = 0;
		FOR (i, 0, N) {
			cin >> tar[i];
			r = max(r, tar[i]);
		}
		sort(tar, tar+N, cmp);

		for (ll i = __lg(max(1, (int)r))+1; i >= 0; i--)
			if (!f(l+(1<<i)))
				l += 1<<i;

		if (l >= r)
			cout << -1 << '\n';
		else
			cout << l+!f(l) << '\n';
	}

    return 0;
}
