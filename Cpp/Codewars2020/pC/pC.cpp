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

bool arr[5][5];

int ans = 0;

void floodfill(int x, int y) {
	
	/* cout << x << ' ' << y << '\n'; */
	arr[x][y] = 0;
	FOR (i, -1, 2)
		FOR (j, -1, 2)
			if (i == 0 || j == 0) {
				int s = x + i, t = y + j;
				if (s >= 0 && s < 5 && t >= 0 && t < 5)
					if (arr[s][t])
						floodfill(s, t);
			}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	FOR (i, 0, 5)
		FOR (j, 0, 5)
			cin >> arr[i][j];
	
	FOR (i, 0, 5)
		FOR (j, 0, 5)
		if (arr[i][j]) {
			ans++;
			floodfill(i, j);
		}

	cout << ans;

    return 0;
}
