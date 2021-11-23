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

int N;
int cnt[1505];

void initialize(int n) {
	memset(cnt, 0, sizeof cnt);
}

int hasEdge(int a, int b) {
	int M = max(a, b);
	cnt[M]++;
	return cnt[M] == M;
}

/* int main() { */

	/* initialize(5); */
	/* cout << hasEdge(1, 5) << '\n'; */
	/* cout << hasEdge(1, 4) << '\n'; */
	/* cout << hasEdge(1, 3) << '\n'; */
	/* cout << hasEdge(1, 2) << '\n'; */
	/* cout << hasEdge(3, 5) << '\n'; */
	/* cout << hasEdge(3, 2) << '\n'; */
	/* cout << hasEdge(3, 4) << '\n'; */
	/* cout << hasEdge(4, 2) << '\n'; */
	/* cout << hasEdge(4, 5) << '\n'; */
	/* cout << hasEdge(2, 5) << '\n'; */

	/* return 0; */
/* } */
