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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t, a, b;
	queue<int> s;
	cin >> t;

	while (t--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			s.push(b);
		} else {
			if (!s.empty()) {
				cout << s.front() << '\n';
				s.pop();
			} else {
				cout << "empty!\n";
			}
		}
	}

    return 0;
}
