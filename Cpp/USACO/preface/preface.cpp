/*
ID: angelus6
TASK: preface
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
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
ofstream fout ("preface.out");
ifstream fin ("preface.in");

int N;
int sym[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
int ans[7] = {};
char val[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int get(int n) {
	int i = 0;
	while (sym[i+1] <= n)
		i++;
	return i;
}

int main() {

	cin >> N;
	FOR (i, 1, N+1) {
		int t = i;
		int s = 13;
		while (s--) {
			int n = t/sym[s];
			if (!(s&1))
				ans[s/2] += n;
			else {
				ans[(s+1)/2] += n;
				if (!(s/2&1))
					ans[(s-1)/2] += n;
				else
					ans[(s-3)/2] += n;
			}
			t -= sym[s]*n;
		}
	}
	vector<int> v;
	FOR (i, 0, 7)
		if (ans[i] > 0)
			v.pb(i);
	FOR (i, 0, v.size())
		cout << val[i] << ' ' << ans[i] << '\n';

	return 0;
}
