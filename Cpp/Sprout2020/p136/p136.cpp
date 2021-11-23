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

const int maxn = 40;
map<ll, ll> dict;

void solve(int N, long long K, long long A[]) {
	
	ll N1 = N / 2;
	ll N2 = N - N / 2;
	for (ll s = 0; s < (1 << N1); s++) {
		ll t = 0;
		FOR (i, 0, N1)
			if (s & (1 << i))
				t += A[i];
		dict[t] = s;
	}

	ll ans1, ans2;
	for (ll s = 0; s < (1 << N2); s++) {
		ll t = 0;
		FOR (i, 0, N2)
			if (s & (1 << i))
				t += A[i + N1];
		if ((ans1 = dict[K - t]) || t == K) {
			ans2 = s;
			break;
		}
	}
	for (ll i = 0; i < N1; i++)
		if (ans1 & (1 << i))
			Report(i + 1);
	for (ll i = 0; i < N2; i++)
		if (ans2 & (1 << i))
			Report(N1 + i + 1);
	Report(-1);

}
