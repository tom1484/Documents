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

const ll maxn = 100005;
ll N, t;

priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N) {
		
		FOR (i, 0, N) {
			cin >> t;
			q.push(t);
		}

		ll a, b, ans = 0;
		while (q.size() > 1) {
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			ans += a+b;
			q.push(a+b);
		}
		cout << ans << '\n';
		q.pop();

		cin >> N;
	}

    return 0;
}
