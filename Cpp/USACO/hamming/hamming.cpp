/*
ID: angelus6
TASK: hamming
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
ofstream fout ("hamming.out");
ifstream fin ("hamming.in");

int N, B, D;
vector<int> ans;

int dis(int a, int b) {
	int res = 0, t = a^b;
	FOR (i, 0, B)
		res += !!(t&(1<<i));
	return res;
}

bool valid(int n) {
	for (int x: ans)
		if (dis(x, n) < D)
			return false;
	return true;
}

int main() {
    
    cin >> N >> B >> D;
	ans.pb(0);
	for (int i = 0; i < (1<<B) && ans.size() < N; i++)
		if (valid(i))
			ans.pb(i);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i%10==9 || i==ans.size()-1];

	return 0;
}
