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

const int maxn = 1e3 + 1;

int T, N, K;
int arr[maxn], mdp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		FOR (i, 0, N)
			cin >> arr[i];

		mdp = 0;
		FOR (i, 1, N) {
			if (i >= K)
				mdp = max(mdp, arr[i - K]);
			arr[i] += mdp;
		}

		int ans = 0;
		FOR (i, 0, N)
			ans = max(arr[i], ans);
		
		cout << ans << '\n';
	}

    return 0;
}
