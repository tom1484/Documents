#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int T;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		if (a >= c)
			cout << -1;
		else
			cout << 1;
		cout << ' ';
		
		if ((ll) a * b <= c)
			cout << -1;
		else
			cout << b;
		cout << '\n';
	}

    return 0;
}
