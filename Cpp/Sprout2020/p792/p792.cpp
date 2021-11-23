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

#define inf 500000001
#define base -500000000

const int maxn = 1e5 + 5;

int N;
ll x[maxn], y[maxn];
ll ans;

int nP, pP;

ll cross(int p0, int p1, int p2) {
	return (x[p1] - x[p0]) * (y[p2] - y[p0]) -
		   (y[p1] - y[p0]) * (x[p2] - x[p0]);
}

int nextP(int i) {
	return (i + 1) % N;
}

int prevP(int i) {
	return (i - 1 + N) % N;
}

void build();
double solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N) {

		ans = 0;
		
		int m = 0;
		ll mv = inf;
		FOR (i, 0, N) {
			cin >> x[i] >> y[i];
			if (x[i] < mv) {
				mv = x[i];
				m = i;
			}
		}

		nP = nextP(m);
		pP = prevP(m);
		ll dir = cross(m, nP, pP);
		if (dir > 0 || (dir == 0 && y[nP] < y[pP])) {
			reverse(x, x + N);
			reverse(y, y + N);
		}

		solve();
		
		FOR (i, 0, N) 
			swap(x[i], y[i]);
		reverse(x, x + N);
		reverse(y, y + N);
	
		solve();

		if (ans % 2)
			cout << ans / 2 << ".5\n";
		else
			cout << ans / 2 << ".0\n";
	}

    return 0;
}

double solve() {

	ll dx, dy, b, dir;
	FOR (i, 0, N) {
		nP = nextP(i);

		dx = x[nP] - x[i];
		dy = y[nP] - y[i];
		
		dir = dx > 0 ? 1 : (dx < 0 ? -1 : 0);
		if (dir == -1)
			dx *= -1, dy *= -1;
		
		if (dir == 0 && dy > 0)
			ans -= 2 * dy;
		else if (dir > 0)
			ans += 2 * y[i] * dx + (dx - 1) * dy;
		else if (dir < 0)
			ans -= 2 * y[i] * dx - (dx + 1) * dy;
	}

	return ans;
}


