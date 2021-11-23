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

ll T, N;

ll primes[4] = {2, 3, 5, 7};

ll cnt[8];
vector<ll> digits;

void split(ll n) {
	for (ll p: primes)
		while (n % p == 0) {
			n /= p;
			cnt[p]++;
		}
	cnt[0] = n != 1;

	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 1) {
			cout << "1\n";
			continue;
		}

		memset(cnt, 0, sizeof cnt);
		split(N);
		if (cnt[0]) {
			cout << "-1\n";
			continue;
		}
		
		digits.clear();
		for (ll p: primes)
			if (p >= 5)
				FOR (i, 0, cnt[p])
					digits.pb(p);

		ll t = cnt[3]/2;
		cnt[3] -= t*2;
		FOR (i, 0, t)
			digits.pb(9);
		
		t = cnt[2]/3;
		cnt[2] -= t*3;
		FOR (i, 0, t)
			digits.pb(8);

		if (cnt[3] && cnt[2]) {
			digits.pb(6);
			cnt[3]--, cnt[2]--;
		}
		else if (cnt[3])
			digits.pb(3);

		t = cnt[2]/2;
		cnt[2] -= t*2;
		FOR (i, 0, t)
			digits.pb(4);

		if (cnt[2])
			digits.pb(2);

		sort(digits.begin(), digits.end());
		for (ll x: digits)
			cout << x;
		cout << '\n';
	}

    return 0;
}
