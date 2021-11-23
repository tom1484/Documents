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

int t, n, a;
stack<int> s;
int arr[1000005], cnt[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> t;
	
	while (t--) {
		while (!s.empty())
			s.pop();
		cin >> n;
		FOR (i, 0, n)
			cin >> arr[i];
			
		ll ans = 0;
		FOR (i, 0, n) {
			cnt[i] = 1;
			while (!s.empty() && arr[s.top()] <= arr[i]) {
				if (arr[s.top()] == arr[i])
					cnt[i] += cnt[s.top()];
				ans += cnt[s.top()];
				s.pop();
			}
			if (!s.empty())
				ans++;
			s.push(i);
		}
		/* cout << ans << " \n"[!!t]; */
		cout << ans << '\n';
	}

    return 0;
}
