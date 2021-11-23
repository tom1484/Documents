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

	int n, t;
	cin >> n;

	stack<int> s;
	while (n--) {
		cin >> t;
		/* bool del = false; */
		if (!s.empty() && s.top() == -t) {
			/* del = true; */
			s.pop();
		}
		else
			s.push(t);
		if (!s.empty() && s.top() < 0)
			break;
	}

	if (s.empty())
		cout << "weed\n";
	else
		cout << "lose light light\n";

    return 0;
}
