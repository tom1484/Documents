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

const int maxn = 10;
const int maxs = 75;
const int maxc = 50;

int N, S, C;
int sarr[maxn][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	memset(sarr, 0, sizeof sarr);

	int cnt = 0, x;
	FOR (i, 0, N) {
		cin >> S;

		FOR (j, 0, S) {
			cin >> C;
			sarr[i][0] += C;

			bool nC = 0;
			FOR (k, 0, C) {
				cin >> x;
				if (x == 11) {
					nC = 1;
					sarr[i][1]++;
				}
			}

			if (nC)
				sarr[i][2] += C;
		}

		if (sarr[i][1] >= 2) {
			sarr[i][2] = sarr[i][0];
			cnt++;
		}
	}

	int ans = 0;
	if (cnt * 3 < N)
		FOR (i, 0, N)
			ans += sarr[i][2];
	else
		FOR (i, 0, N)
			ans += sarr[i][0];

	cout << ans << '\n';

    return 0;
}
