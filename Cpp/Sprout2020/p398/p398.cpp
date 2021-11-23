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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	char c;
	vector<ll> arr(N);
	FOR (i, 0, N)
		cin >> c >> c >> arr[i];

	int ans = 0;
	FOR (i, 0, N)
		FOR (j, 0, N)
			FOR (k, 0, N)
				if (arr[i] + arr[j] == arr[k])
					ans++;
	cout << ans << '\n';

    return 0;
}

/**
3
0.100000000
0.200000000
0.300000000
**/