/*
ID: angelus6
TASK: runround
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
ifstream fin("runround.in");
ofstream fout("runround.out");

ull b;

bool valid(ull n) {

	string s = to_string(n);
	bool vis[10] = {};
	int i = 0, cnt = 0, t;
	while (cnt < s.size()) {
		if (!s[i] || vis[s[i]-'0'])
			return false;
		t = i+s[i]-'0';
		vis[s[i]-'0'] = true;
		s[i] = 0;
		cnt++;
		i = t%s.size();
	}
	return i==0;
}

int main() {
	
	cin >> b;
	++b;
	while (!valid(b))
		b++;

	cout << b << '\n';

	return 0;
}
