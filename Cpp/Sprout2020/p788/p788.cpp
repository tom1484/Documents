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

const int maxn = 5 * 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, N, IDX, ans;
int arr[maxn], turn[maxn];
vector<int> cnt[maxn];

void solve(int lt, int rt) {
	
	if (rt - lt <= 1)
		return ;

	int res = 0, mid = (lt + rt) / 2;

	

	solve(lt, mid);
	solve(mid, rt);

}

int main() {
	/* ios::sync_with_stdio(false); */
	/* cin.tie(NULL); */

	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i, 0, N)
			cin >> arr[i];
		
		IDX = 0, ans = N;
		memset(cnt, 0, sizeof cnt);

		solve(0, N);
		reverse(arr, arr + N);
		solve(0, N);

		cout << ans << "\n\n\n";
	}

    return 0;
}
