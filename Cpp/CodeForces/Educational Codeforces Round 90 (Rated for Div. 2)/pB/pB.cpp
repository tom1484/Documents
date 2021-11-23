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

typedef list<bool>::iterator iter;

int T;
list<bool> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	string str;
	while (T--) {
		cin >> str;
		FOR (i, 0, str.size())
			arr.pb(str[i] == '1');

		int cnt = 0;
		while (arr.size() > 1) {
			bool valid = false;
			iter s, t;
			s = t = arr.begin();
			t++;
			for (; t != arr.end(); s++, t++)
				if (*s != *t) {
					cnt++;
					valid = true;
					arr.erase(s);
					arr.erase(t);
					break;
				}
			if (!valid)
				break;
		}

		cout << (cnt % 2 ? "DA" : "NET") << '\n';
		arr.clear();
	}

    return 0;
}
