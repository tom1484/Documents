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

#define inf 0x3f3f3f3f3f3f3f3f
#define ninf -inf

struct Point {
	ll x, y;
};

struct Frac {
	ll a, b;
	
	Frac(): a(0), b(0) {}
	
	Frac(ll x, ll y): a(x), b(y) {
		
		if (b == 0) {
			a = inf;
			b = 1;
		}
		else if (a == 0)
			b = 1;
		else {
			ll g = __gcd(a, b);
			a /= g, b /= g;
			if (b < 0)
				a *= -1, b *= -1;
		}

	}

	bool operator==(Frac t) {
		return a == t.a && b == t.b;
	}

	bool operator<(Frac t) {
		return (double)a / b < (double)t.a / t.b;
	}
};

struct Line {
	int p1, p2;
	Frac a, b;

	Line() {}
	
	Line(int n1, int n2): p1(n1), p2(n2) {}

	bool operator<(Line t) {
		return a == t.a ? b < t.b : a < t.a;
	}

	bool operator==(Line t) {
		return a == t.a && b == t.b;
	}
};

const int maxn = 2401;

int N;
Point arr[maxn];
vector<Line> segs;
int vis[maxn];

Line buildLine(int n1, int n2) {
	
	Line line(n1, n2);
	Point p1 = arr[n1];
	Point p2 = arr[n2];

	line.a = Frac(p2.y - p1.y, p2.x - p1.x);
	if (line.a.a < inf && line.a.a > ninf)
		line.b = Frac(p1.y * line.a.b - line.a.a * p1.x, line.a.b);
	else
		line.b = Frac(p1.x, 1);

	return line;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> 	N;
	FOR (i, 0, N)
		cin >> arr[i].x >> arr[i].y;

	FOR (i, 0, N)
		FOR (j, i + 1, N)
			segs.pb(buildLine(i, j));
	sort(segs.begin(), segs.end());

	FOR (i, 0, segs.size()) {
		cout << segs[i].p1 << ' ' << segs[i].p2 << '\n';
		cout << segs[i].a.a << '/' << segs[i].a.b << ", ";
		cout << segs[i].b.a << '/' << segs[i].b.b << '\n';
	}

	memset(vis, 0, sizeof vis);
	ll ans = (ll) N * (N - 1) * (N - 2) / 6;
	int cnt = 0, b = 0, t = 1;

	FOR (i, 0, segs.size()) {
		if (!(segs[i] == segs[b])) {
			if (cnt > 2)
				ans -= (ll) cnt * (cnt - 1) * (cnt - 2) / 6;
			cnt = 0;
			b = i, t++;
		}

		if (vis[segs[i].p1] != t)
			cnt++;
		if (vis[segs[i].p2] != t)
			cnt++;
		vis[segs[i].p1] = vis[segs[i].p2] = t;
		/* cout << ans << ' ' << cnt << '\n'; */
	}
	if (cnt > 2)
		ans -= (ll) cnt * (cnt - 1) * (cnt - 2) / 6;

	/* cout << ans << '\n'; */
	cout << ans;

    return 0;
}
