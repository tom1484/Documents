#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

int T, n, t, cnt;
stack<int> s;
int arr[100005];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> n;
		while (!s.empty())
			s.pop();

		cnt = 0;
		FOR (i, 0, n) 
			cin >> arr[i];
		FOR (i, 1, n+1) {
			s.push(i);
			while (!s.empty() && s.top() == arr[cnt]) {
				s.pop();
				cnt++;
			}
		}

		if (s.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
