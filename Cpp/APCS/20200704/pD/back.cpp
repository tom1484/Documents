#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 1000;
const int maxm = 80;

struct Node {
	int prt, dep;
	int rna[maxm];
	int cnt[4];
	vector<int> cand;
};

int N, M, D = 0;
Node arr[maxn] = {};
vector<vector<int>> depth;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int toInt[26];
	toInt['A' - 'A'] = 0;
	toInt['U' - 'A'] = 1;
	toInt['G' - 'A'] = 2;
	toInt['C' - 'A'] = 3;

	cin >> N >> M;

	int a, b;
	string str;
	FOR (i, 0, N) {
		cin >> a >> b >> str;
		a--, b--;
		
		arr[a].prt = b;
		FOR (j, 0, M)
			arr[a].rna[j] = (str[j] == '@' ? -1 : toInt[str[j] - 'A']);

		arr[a].dep = (a == b ? 0 : arr[b].dep + 1);
		D = max(D, arr[a].dep);
		if (depth.size() <= arr[a].dep)
			depth.pb(vector<int>());
		depth[arr[a].dep].pb(a);
	}

	int ans = 0;

	FOR (j, 0, M) {
		FOR (i, 0, N) {
			memset(arr[i].cnt, 0, sizeof arr[i].cnt);
			arr[i].cand.clear();
		}

		RFOR (z, depth.size(), 0) {
			vector<int> &v = depth[z];
			/* for (int i: v) */
				/* cout << i << ' '; */
			/* cout << '\n'; */
			for (int i: v) {
				if (arr[i].rna[j] == -1) {
					int cn = 0;
					FOR (k, 0, 4)
						cn = max(cn, arr[i].cnt[k]);
					FOR (k, 0, 4)
						if (arr[i].cnt[k] == cn)
							arr[i].cand.pb(k);
				}
				else
					arr[i].cand.pb(arr[i].rna[j]);

				int prt = arr[i].prt;
				for (int x: arr[i].cand)
					arr[prt].cnt[x]++;

				/* cout << i << ": "; */
				/* for (int x: arr[i].cand) */
					/* cout << x << ' '; */
				/* cout << '\n'; */
			}
		}

		FOR (z, 0, depth.size()) {
			vector<int> &v = depth[z];
			for (int i: v) {
				int prt = arr[i].prt;
				if (arr[i].rna[j] == -1) {
					arr[i].rna[j] = arr[i].cand[0];
					if (i)
						for (int x: arr[i].cand)
							if (x == arr[prt].rna[j]) {
								arr[i].rna[j] = x;
								break;
							}
				}

				if (i && arr[i].rna[j] != arr[prt].rna[j])
					ans++;
			}
		}
	}

	cout << ans << '\n';

    return 0;
}
