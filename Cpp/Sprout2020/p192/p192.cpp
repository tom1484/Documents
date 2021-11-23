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

#define Iter list<Point>::iterator
#define inf 0x3f3f3f3f3f3f3f3f
#define ninf -0x3f3f3f3f3f3f3f3f


struct Point {
	ll x, y;
};

const int maxn = 1e5;

int N;

list<Point> arr;
Point p[3];

Iter nextP(Iter it) {
	Iter r = it;
	++r;
	return r == arr.end() ? arr.begin() : r;
}

Iter prevP(Iter it) {
	Iter r = it;
	if (it == arr.begin())
		r = arr.end();
	--r;
	return r;
}

ll cross() {
	return (p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[1].y - p[0].y) * (p[2].x - p[0].x);
}

double calcX(bool cut) {

	double res = 0, c;
	ll dx;

	if (p[0].x != p[1].x && p[0].x != p[2].x) {
		c = double(p[2].y - p[0].y) / (p[2].x - p[0].x) - 
			double(p[1].y - p[0].y) / (p[1].x - p[0].x);
		dx = abs(p[1].x - p[0].x);
		res += abs(dx * (dx + 1) * c / 2);
		
		if (p[1].x == p[2].x)
			res -= abs(dx * c);
		else if (cut)
			res -= abs(dx * c);
	}
	/* cout << res << '\t'; */

	return res;
}

double calcY(bool cut) {

	double res = 0, c;
	ll dy;

	if (p[0].y != p[1].y && p[0].y != p[2].y) {
		c = double(p[2].x - p[0].x) / (p[2].y - p[0].y) - 
			double(p[1].x - p[0].x) / (p[1].y - p[0].y);
		dy = abs(p[1].y - p[0].y);
		res += abs(dy * (dy + 1) * c / 2);
		
		if (p[1].y == p[2].y)
			res -= abs(dy * c);
		else if (cut)
			res -= abs(dy * c);
	}

	/* cout << res << '\t'; */

	return res;
}

double solve() {
	
	double res = 0, c;
	ll dx, dy;

	sort(p, p + 3, [](Point a, Point b) {
		return a.x < b.x;
	});
	
	res += calcX(false);
	
	swap(p[0], p[2]);
	res += calcX(true);

	sort(p, p + 3, [](Point a, Point b) {
		return a.y < b.y;
	});

	res += calcY(false);

	swap(p[0], p[2]);
	res += calcY(true);

	/* cout << res << '\n'; */
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N) {

		arr.clear();

		ll Mv = ninf;
		Iter M = arr.begin();
		FOR (i, 0, N) {
			Point p;
			cin >> p.x >> p.y;
			arr.push_back(p);
			
			if (p.x > Mv) {
				Mv = p.x;
				M = prevP(arr.end());
			}
		}

		p[0] = *prevP(M);
		p[1] = *M;
		p[2] = *nextP(M);
		if (cross() > 0)
			arr.reverse();
		else if (cross() == 0 && p[0].y < p[1].y)
			arr.reverse();

		double ans = 0;
		for (Iter it = arr.begin(); arr.size() > 2; ) {
			p[0] = *it;
			p[1] = *nextP(it);
			p[2] = *nextP(nextP(it));
			
			/* FOR (i, 0, 3) */
				/* cout << p[i].x << ',' << p[i].y << '/'; */
			/* cout << '\t'; */

			if (cross() <= 0) {
				ans += solve();
				arr.erase(nextP(it));
			}
			it = nextP(it);
		}

		cout << ans << "\n";

	}

    return 0;
}
