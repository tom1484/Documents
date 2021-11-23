#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

int T, N;
double a[10], b[10], c[10];

double f(int i, double t) {
	return a[i] * (t - b[i]) * (t - b[i]) + c[i];
}

double maxVal(double t) {
	double res = -1e18;
	FOR (i, 0, N)
		res = max(res, f(i, t));
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> a[i] >> b[i] >> c[i];
		/* cout << f(1, 100); */

		double l = 0, a, b, r = 300;
		double aVal, bVal;
		FOR (i, 0, 200) {
			a = l + (r - l) * 1.0 / 3.0;
			b = l + (r - l) * 2.0 / 3.0;
			aVal = maxVal(a);
			bVal = maxVal(b);
			/* printf("%.5f %.5f\n", aVal, bVal); */

			if (aVal < bVal) r = b;
			else if (aVal > bVal) l = a;
			else l = a;
		}
		printf("%.5f\n", aVal);
	}

    return 0;
}
