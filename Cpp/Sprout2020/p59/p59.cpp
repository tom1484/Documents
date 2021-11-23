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

priority_queue<int, vector<int>, greater<int>> Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, c, t;
	cin >> T;

	while (T--) {
		cin >> c;
		if (c == 1) {
			cin >> t;
			Q.push(t);
		}
		else if (Q.empty())
			cout << "empty!\n";
		else {
			cout << Q.top() << '\n';
			Q.pop();
		}
	}

    return 0;
}
