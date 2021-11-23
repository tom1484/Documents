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

const int maxn = 1e5 + 5;

int T, N, K, C, dp;
int arr[maxn];
pii Q[maxn];
int head, tail;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> K >> C;
		FOR (i, 0, N) 
			cin >> arr[i];
		
		int ans = arr[0];
		Q[0] = mp(0, arr[0]);
		head = 0, tail = 0;
		FOR (i, 1, N) {
			
			dp = max(arr[i], arr[i] + Q[head].sd - i * C);
			ans = max(ans, dp);
			
			while (tail >= head && Q[tail].sd < dp + i * C)
				tail--;
			Q[++tail] = mp(i, dp + i * C);
			
			if (i - Q[head].ft == K)
				head++;
		}

		cout << ans << '\n';
	}

    return 0;
}
