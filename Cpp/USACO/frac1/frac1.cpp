/*
ID: angelus6
TASK: frac1
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("frac1.out");
ifstream fin ("frac1.in");

struct Frac {
	int a, b;
	Frac(int a, int b): a(a), b(b) {}
	Frac() {}
};

int n;
int vis[161][161] = {};
vector<Frac> fracs;

int main() {
	
	cin >> n;

	fracs.pb(Frac(1, 1));
	vis[1][1] = true;
	FOR (i, 0, n+1)
		FOR (j, i+1, n+1) {
			int a = i, b = j;
			int gcd = __gcd(a, b);
			a /= gcd, b /= gcd;
			if (!vis[a][b])
				fracs.pb(Frac(a, b));
			vis[a][b] = true;
		}

	sort(fracs.begin(), fracs.end(), [](Frac& a, Frac& b) {
				int gcd = __gcd(a.b, b.b);
				return a.a*b.b/gcd < b.a*a.b/gcd;
			});
	for (Frac f: fracs)
		cout << f.a << '/' << f.b << '\n';

	return 0;
}
