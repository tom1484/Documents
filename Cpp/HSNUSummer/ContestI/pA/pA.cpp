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

const int maxn = 200005;

int N, K;

string str;
int d[maxn];

priority_queue<int> Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	FOR (i, 0, N)
		cin >> d[i];
	cin >> str;
	str += ' ';

	ll ans = 0;
	int curr = str[0];
	Q.push(d[0]);

	FOR (i, 1, N + 1) {
		if (str[i] != curr) {
			for (int j = 0; j < K && !Q.empty(); j++)
				if (j < K) {
					ans += Q.top();
					Q.pop();
				}
			while (!Q.empty())
				Q.pop();
			curr = str[i];
		}
		Q.push(d[i]);
	}

	cout << ans << '\n';

    return 0;
}
