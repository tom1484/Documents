/*
ID: angelus6
TASK: zerosum
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
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int n;

pii getInt(string s, int st) {
	int res = 0, i = st;
	for (; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-')
			break;
		if (s[i] == ' ')
			continue;
		res *= 10;
		res += s[i]-'0';
	}
	return make_pair(res, i);
}

int calc(string s) {
	pii f = getInt(s, 0);
	int a = f.ft, b = 0, o, i = f.sd;
	while (i < s.size()) {
		o = s[i];
		f = getInt(s, i+1);
		b = f.ft, i = f.sd;
		if (o == '+')
			a += b;
		else
			a -= b;
	}
	return a;
}

int main() {

	cin >> n;
	string base = "";
	FOR (i, 1, n+1) {
		base += '0'+i;
		if (i < n)
			base += ' ';
	}
	
	int p = 1;
	FOR (i, 1, n)
		p *= 3;

	FOR (i, 0, p) {
		string form = base;
		int p = n*2-3, t = i;
		while (t) {
			switch (t%3) {
				case 0:
					form[p] = ' ';
					break;
				case 1:
					form[p] = '+';
					break;
				case 2:
					form[p] = '-';
					break;
			}
			t /= 3;
			p -= 2;
		}
		if (calc(form) == 0)
			cout << form << '\n';
	}

	return 0;
}
