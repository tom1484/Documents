/*
ID: angelus6
TASK: lamps
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("lamps.in");
ofstream fout("lamps.out");

int n, c;
int rule[1<<4] = {};

int getIdx(int i) {
	int s = 1;
	s <<= 1;
	if (i&1) s++;
	s <<= 1;
	if (!(i&1)) s++;
	s <<= 1;
	if (i%3==1) s++;
	
	return s;
}

int countOne(int s) {
	int res = 0;
	while (s) {
		if (s&1)
			res++;
		s >>= 1;
	}
	return res;
}

int main() {

	cin >> n >> c;
	
	int t, r;
	bool poss = true;
	FOR (i, 0, 2)
		while (cin >> t) {
			if (t == -1) 
				break;
			int s = getIdx(t);
			r = i ? 1 : 2;
			if (rule[s] && rule[s] != r)
				poss = false;
			rule[s] = r;
		}

	if (poss) {
		vector<int> com;
		FOR (i, 0, (1<<4))
			if ((countOne(i)&1) == (c&1) && countOne(i) <= c) {			
				/* RFOR (j, 3, -1) */
				/* 	cout << !!(i&(1<<j)); */
				/* cout << '\n'; */
				bool valid = true;
				FOR (r, 0, (1<<4))
					if (valid && rule[r]) {
						int cnt = 0;
						FOR (j, 0, 4)
							if (r&(1<<j))
								cnt += !!(i&(1<<j));
						valid = ((cnt&1) == (rule[r]&1));
					}
				if (valid)
					com.pb(i);
			}
		/* for (int x: com) { */
		/* 	RFOR (i, 3, -1) */
		/* 		cout << !!(x&(1<<i)); */
		/* 	cout << '\n'; */
		/* } */

		vector<string> ans;
		for (int x: com) {
			string s = "";
			FOR (i, 1, n+1) {
				t = 1;
				if (i%3==1 && !!(x&(1)))
					t = 1-t;
				if (!(i&1) && !!(x&(2)))
					t = 1-t;
				if ((i&1) && !!(x&(4)))
					t = 1-t;
				if (!!(x&(8)))
					t = 1-t;
				s += t+'0';
			}
			ans.pb(s);
		}
		sort(ans.begin(), ans.end());
		int sz = unique(ans.begin(), ans.end())-ans.begin();
		FOR (i, 0, sz)
			cout << ans[i] << '\n';
		if (!sz)
			cout << "IMPOSSIBLE\n";
	}
	if (!poss)
		cout << "IMPOSSIBLE\n";

	return 0;
}
