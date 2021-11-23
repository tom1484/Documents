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

int t, n = 0;
int arr[2005];

void post(int lt, int rt) {
	
	/* cout << lt << ' ' << rt << '\n'; */
	if (rt-lt <= 0)
		return ;

	int p = arr[lt++];
	int mid = lt;

	while (mid < rt && arr[mid] < p)
		mid++;

	post(lt, mid);
	post(mid, rt);
	cout << p << '\n';

	return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (cin >> t)
		arr[n++] = t;

	post(0, n);

    return 0;
}
