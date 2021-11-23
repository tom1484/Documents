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

int k, cnt = -1;
int arr[13], ans[13];

void solve(int idx, int d) {
	ans[d-1] = arr[idx];
	if (d == 6) {
		if (cnt)
			cout << '\n';
		FOR (i, 0, 5)
			cout << ans[i] << ' ';
		cout << ans[5];
		cnt++;
		return ;
	}
	FOR (i, idx+1, k-5+d)
		solve(i, d+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> k;
	while (k) {
		if (cnt >= 0)
			cout << "\n\n";
		FOR (i, 0, k)
			cin >> arr[i];
		
		cnt = 0;
		FOR (i, 0, k-5)
			solve(i, 1);
		cin >> k;
	}

    return 0;
}
