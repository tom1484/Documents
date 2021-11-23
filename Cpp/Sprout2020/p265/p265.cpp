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

const int maxn = 5e5;

int N, M;
string A, B;
int fail[maxn];
vector<int> ans;

void failure();

int main() {
	/* ios::sync_with_stdio(false); */
	/* cin.tie(NULL); */

	cin >> A >> B;
	N = A.size();
	M = B.size();

	failure();
	/* for (int i = 0;) */
	/* FOR (i, 0, N) */
		/* cout << fail[i] << '\n'; */

	for (int i = 0, j = -1; i < M; i++) {
		while (j >= 0 && A[j + 1] != B[i])
			j = fail[j];
		if (B[i] == A[j + 1])
			j ++;
		if (j == N - 1) {
			ans.pb(i - j);
			j = fail[j];
		}
	}

	if (ans.size()) {
		cout << ans[0];
		FOR (i, 1, ans.size())
			cout << ' ' << ans[i];
	}
	cout << '\n';

    return 0;
}

void failure() {

	for (int i = 1, j = fail[0] = -1; i < N; i++) {
		while (j >= 0 && A[j + 1] != A[i])
			j = fail[j];
		if (A[j + 1] == A[i])
			fail[i] = ++j;
		else
			fail[i] = -1;
	}

}







