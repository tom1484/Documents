/*
ID: angelus6
TASK: pprime
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("pprime.out");
ifstream fin ("pprime.in");

bool ptable[10000];
vector<int> prime;

int a, b;
vector<int> ans;

inline int rev(int i) {
	int res = 0;
	while (i) {
		res += i%10;
		res *= 10, i /= 10;
	}
	return res/10;
}

inline bool isprime(int n) {
	for (int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++) {
		if (!(n%prime[i]))
			return false;
	}
	return true;
}

int main() {

	memset(ptable, 0, sizeof ptable);
	ptable[2] = false;
	FOR (i, 2, 10000) {
		if (!ptable[i]) {
			for (int j = i+i; j < 10000; j += i)
				ptable[j] = true;
			prime.pb(i);
		}
	}

	cin >> a >> b;

	int l = 1, u = 10;
	FOR (d, 1, 4) {
		FOR (i, l, u-1) {
			int t = i*l+rev(i/10);
			if (isprime(t) && t >= a && t <= b)
				ans.pb(t);
			t = i*u+rev(i);
			if (isprime(t) && t >= a && t <= b)
				ans.pb(t);
		}
		l *= 10, u *= 10;
	}
	
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}
