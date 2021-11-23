#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

ll n, t;
ll arr[200005];
stack<ll> s;

int main() {
    /* ios::sync_with_stdio(false); */
    /* cin.tie(NULL); */

	cin >> n;
	FOR (i, 1, n+1)
		scanf("%lld", &arr[i]);
	arr[0] = arr[n+1] = 0;

	ll ans = 0;
	FOR (i, 0, n+2) {
		while (s.size() > 1 && arr[s.top()] >= arr[i]) {
			t = s.top();
			s.pop();
			ll width = i-s.top()-1;
			ans = max(ans, arr[t] * width);
		}
		s.push(i);
	}
	printf("%lld\n", ans);

    return 0;
}
