#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pdd pair<double, double>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

ll dis(pdd a, pdd b) {
	ll d1 = a.ft - b.ft;
	ll d2 = a.sd - b.sd;
	return d1 * d1 + d2 * d2;
}

vector<pair<ll, ll>> points;
vector<ll> arr;
map<ll, ll> D;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	ll a, b;
	FOR (i, 0, N) {
		cin >> a >> b;
		points.pb(mp(a, b));
	}
	FOR (i, 0, N)
		FOR (j, i + 1, N)
			D[dis(points[i], points[j])]++;

	ll ans = 0;
	for (map<ll, ll>::iterator it = D.begin(); it != D.end(); it++)
		ans += (*it).sd * ((*it).sd - 1) / 2;

	cout << ans << '\n';

    return 0;
}

/**
4
1 1
1 2
2 1
2 2
**/