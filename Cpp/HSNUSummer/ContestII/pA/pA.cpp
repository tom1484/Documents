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

const int maxn = 500005;

int N;

int arr[maxn];

ll ans[maxn];
ll pre[maxn];

stack<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	FOR (i, 0, N)
		cin >> arr[i];

	FOR (i, 0, N)
		ans[i] = 0;
	
	FOR (i, 0, N)
		pre[i] = 0;

	S.push(-1);

	FOR (i, 0, N) {
		while (S.size() > 1 && arr[S.top()] >= arr[i])
			S.pop();
		
		pre[i] += (ll)(i - S.top()) * arr[i];
		if (S.size() > 1)
			pre[i] += pre[S.top()];

		S.push(i);
	}

	FOR (i, 0, N)
		ans[i] = pre[i];

	FOR (i, 0, N)
		pre[i] = 0;

	reverse(arr, arr + N);
	while (S.size() > 1)
		S.pop();

	FOR (i, 0, N) {
		while (S.size() > 1 && arr[S.top()] >= arr[i])
			S.pop();
		
		pre[i] += (ll)(i - S.top()) * arr[i];
		if (S.size() > 1)
			pre[i] += pre[S.top()];

		S.push(i);
	}

	FOR (i, 0, N)
		ans[N - i - 1] += pre[i] - arr[i];

	ll a = 0;

	FOR (i, 0, N)
		a = max(a, ans[i]);

	cout << a << '\n';

    return 0;
}
