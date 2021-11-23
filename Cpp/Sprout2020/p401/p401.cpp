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
	ll operator*(Vector v) {
		return x * v.y - y * v.x;
	}
	Vector operator-(Vector v) {
		return Vector(x - v.x, y - v.y);
	}
};

bool inter2D(Vector p1, Vector p2, Vector q1, Vector q2) {
	ll res1 = (p1 - q1) * (p1 - q2);
	res1 = (res1 != 0 ? (res1 < 0 ? -1 : 1) : 0);
	ll res2 = (p2 - q1) * (p2 - q2);
	res2 = (res2 != 0 ? (res2 < 0 ? -1 : 1) : 0);
	ll res3 = (q1 - p1) * (q1 - p2);
	res3 = (res3 != 0 ? (res3 < 0 ? -1 : 1) : 0);
	ll res4 = (q2 - p1) * (q2 - p2);
	res4 = (res4 != 0 ? (res4 < 0 ? -1 : 1) : 0);
	return res1 * res2 <= 0 && res3 * res4 <= 0;
}

bool inter1D(int p1, int p2, int q1, int q2) {
	if (p1 > p2)
		swap(p1, p2);
	if (q1 > q2)
		swap(q1, q2);
	return max(p1, q1) <= min(p2, q2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	Vector p1, p2, q1, q2;
	FOR (i, 0, N) {
		cin >> p1.x >> p1.y;
		cin >> p2.x >> p2.y;
		cin >> q1.x >> q1.y;
		cin >> q2.x >> q2.y;
		if (inter2D(p1, p2, q1, q2) && 
			inter1D(p1.x, p2.x, q1.x, q2.x) && 
			inter1D(p1.y, p2.y, q1.y, q2.y))
			cout << "Yes\n";
		else
			cout << "No\n";
	}


    return 0;
}

/**
3
0 0 2 0 0 1 2 1
0 0 2 0 1 1 1 -1
0 0 2 0 3 1 3 -1
**/