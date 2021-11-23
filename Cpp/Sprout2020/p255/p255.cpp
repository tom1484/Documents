#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll __int64_t
#define ull __uint64
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

struct Frac;
struct Curve;
struct Point;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

struct Frac {
	ll a, b;
	Frac(): a(0), b(1) {}
	Frac(ll a, ll b): a(a), b(b) {
		ll g = gcd(a, b);
		a /= g, b /= g;
	}
	
	Frac operator+(Frac t) {
		ll g = b * t.b / gcd(b, t.b);
		return Frac(a * g / b + t.a * g / t.b, g);
	}

	Frac operator*(ll t) {
		return Frac(a * t, b);
	}

	ll toInt() {
		return a / b;
	}
};

struct Curve {
	Frac a, b;
	Curve(Frac a, Frac b): a(a), b(b) {}
};

struct Point {
	ll x, y;
	Point(): x(0), y(0) {}
	Point(ll x, ll y): x(x), y(y) {}
};

bool onCurve(Curve c, Point p) {
	Frac fx = c.a * p.x + c.b;
	ll lt = p.y * fx.b;
	if (!(lt % p.x))
		return lt / p.x == fx.a;
	else
		return false;
	/* Frac fx = c.a * p.x * p.x + c.b * p.x; */
	/* return p.y * fx.b == fx.a; */
}

Curve getCurve(Point p1, Point p2) {
	if (p1.x * p2.y == p1.y * p2.x)
		return Curve(Frac(), Frac());
	
	ll a1 = p1.x * p1.x;
	ll b1 = p1.x;
	ll c1 = p1.y;
	ll a2 = p2.x * p2.x;
	ll b2 = p2.x;
	ll c2 = p2.y;

	ll d = a1 * b2 - b1 * a2;
	ll dx = c1 * b2 - b1 * c2;
	ll dy = a1 * c2 - c1 * a2;
	Curve c = Curve(Frac(dx, d), Frac(dy, d));

	return c;
}

const int maxn = 24;

int T, N;
Point points[maxn];
int kills[maxn][maxn];
int dp[1 << maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;

		int x, y;
		FOR (i, 0, N) {
			cin >> x >> y;
			points[i] = Point((ll)x, (ll)y);
		}

		FOR (i, 0, N)
			FOR (j, i, N) {
				ll res = 0;
				Curve c = getCurve(points[i], points[j]);
				if ((ll)c.a.a * c.a.b < 0) {
					FOR (k, 0, N)
						if (onCurve(c, points[k])) 
							res += (1 << k);
				}
				kills[i][j] = kills[j][i] = res;
			}

		dp[0] = 0;
		FOR (s, 1, (1 << N)) {
			ll i = 0;
			while (!(s & (1 << i)))
				i++;

			dp[s] = dp[s - (1 << i)] + 1;
			FOR (j, i + 1, N)
				if (kills[i][j]) {
					dp[s] = min(dp[s], dp[s - (s & kills[i][j])] + 1);
				}
		}
		cout << (int) dp[(1 << N) - 1] << '\n';
	}

    return 0;
}
