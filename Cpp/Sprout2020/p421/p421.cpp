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

int T, N, M, A;

vector<int> arr;

void add(int x) {

	int p = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	if (p < arr.size())
		arr[p] = x;
	else
		arr.pb(x);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		arr.clear();
		cin >> N >> M;
		FOR (i, 0, N) {
			cin >> A;
			if (2 * A >= M) add(2 * A);
			if (A >= M) add(A);
		}
		cout << arr.size() << '\n';
	}

    return 0;
}
