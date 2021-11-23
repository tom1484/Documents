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

int N, t;
vector<int> arr, pre;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (scanf("%d", &t) != EOF)
		arr.pb(t);
	N = arr.size();
	reverse(arr.begin(), arr.end());
	
	FOR (i ,0, N)
		pre.pb(0);
	pre[0] = 1;
	arr[0] = -1;

	FOR (i, 1, N) {
		pre[i] = pre[i - 1];
		if (arr[i] >= i) {
			arr[i] = -1;
			pre[i] += 1;
		}
		else {
			t = i - arr[i] - 1;
			t = pre[i - 1] - (t >= 0 ? pre[t] : 0);
			if (t) {
				arr[i] = -1;
				pre[i] += 1;
			}
		}
	}

	/* FOR (i, 0, N) */
		/* cout << arr[i] << ' '; */
	/* cout << '\n'; */

	if (arr[N - 1] < 0)
		cout << "True";
	else
		cout << "False";

    return 0;
}
