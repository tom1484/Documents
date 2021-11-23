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

struct Edge {
	int to, cost;
	Edge(int b, int c):
		to(b), cost(c) {}
};

int N;

bool num[26] = {0};

int s, t, p1, p2;
vector<Edge> G[26];
vector<Edge> edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	
	cin >> c; s = c - 'A';
	cin >> c; t = c - 'A';
	cin >> c; p1 = c - 'A';
	cin >> c; p2 = c - 'A';

		cout << s << ' ' << t << ' ' << p1 << ' ' << p2 << '\n';


	int a, b, w;
	while (cin >> c) {
		a = c - 'A';
		cin >> c >> c;
		cin >> c; b = c - 'A';
		cin >> c;	

		cin >> w;
		cout << a << ' ' << b << ' ' << w << '\n';

		G[a].pb(Edge(b, w));
		/* if (!num[a]) { */
			/* num[a] = 1; */
			/* N++; */
		/* } */
		/* if (!num[b]) { */
			/* num[b] = 1; */
			/* N++; */
		/* } */

		/* edges.pb(Edge(a, b, w)); */
	}

	

    return 0;
}
