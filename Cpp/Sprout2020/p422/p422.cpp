#include <iostream>
#include <algorithm>
using namespace std;

#define uint __uint32_t
#define ll __int64_t
#define ull __uint64_t
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 4000;

int N;
pii arr[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N) {
		FOR (i, 0, N)
			cin >> arr[i].ft >> arr[i].sd;
		sort(arr, arr + N);
		
		

		cin >> N;
	}

    return 0;
}
