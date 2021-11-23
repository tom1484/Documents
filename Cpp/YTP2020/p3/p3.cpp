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

const int maxn = 1000;
const int maxm = 8;

int N, M;
bool arr[maxn][maxm];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	string str;
	getline(cin, str);
	
	FOR (i, 0, N) {
		getline(cin, str);
		FOR (j, 0, M)
			arr[i][j] = str[j] == 'X';
	}

	int ans = 0;
	FOR (j, 0, M) {
		int cnt = 0;
		FOR (i, 0, N) {
			if (arr[i][j]) {
				if (cnt == 0)
					ans++;
				cnt++;
			}
			else
				cnt = 0;
		}
	}

	cout << ans << '\n';

    return 0;
}
