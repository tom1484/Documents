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

struct Vector {
	ll x, y;
	Vector() {}
	Vector(ll x, ll y): x(x), y(y) {}
	ll dot(Vector v) {
		return x * v.x + y * v.y;
	}
	ll cross(Vector v) {
		return x * v.y - y * v.x;
	}
	Vector operator-(Vector v) {
		return Vector(x - v.x, y - v.y);
	}
};

const int maxn = 1e6 + 1;

Vector arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	FOR (i, 0, N)
		cin >> arr[i].x >> arr[i].y;

	int l = 0, r = 0, b = 0;
	Vector v = arr[1] - arr[0];
	FOR (i, 2, N) {
		Vector u = arr[i] - arr[i - 1];
		ll c = v.cross(u);
		if (c > 0) l++;
		else if (c < 0) r++;
		else if (v.dot(u) < 0) b++;
		v = u;
	}

	cout << l << ' ' << r << ' ' << b << '\n';

    return 0;
}

/**
5
0 0
0 1
1 1
1 2
1 0
**/