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

const int maxn = 1e6 + 5;
const int ninf = 0xc0c0c0c0;

int N, M, L;
int ans[maxn];

void divide(int L1, int R1, int L2, int R2) {
	
	if (R1 - L1 < 1)
		return ;

	int M1 = (L1 + R1) / 2;
	int ms = max(L2, M1);
	int me = min(R2, M1 + L);
	int tmp, v;
	tmp = ninf;
	FOR (i, ms, me) {
		v = GetVal(M1, i);
		if (v > tmp) {
			ans[M1] = i;
			tmp = v;
		}
	}
	
	divide(L1, M1, L2, ans[M1]);
	divide(M1 + 1, R1, ans[M1] + 1, R2);

}

void solve(int n, int m) {
	N = n, M = m;
	L = M - N + 1;
	divide(1, N + 1, 1, M + 1);
	FOR (i, 1, N + 1)
		Report(ans[i]);
}
