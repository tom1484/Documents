/**
ID: angelus6
TASK: cowtour
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

const int maxn = 150;

int N;
char c;
pii pos[maxn];
bool edge[maxn][maxn];
double path[maxn][maxn];
double diam[maxn];

int main () {

	cin >> N;
	FOR (i, 0, N)
		cin >> pos[i].ft >> pos[i].sd;
	
	FOR (i, 0, N) 
		FOR (j, 0, N) {
			cin >> c;
			edge[i][j] = c-'0';
			if (edge[i][j] || i == j)
				path[i][j] = path[j][i] = 
					sqrt(pow(pos[i].ft-pos[j].ft, 2)+pow(pos[i].sd-pos[j].sd, 2));
			else
				path[i][j] = path[j][i] = 1e9;
		}

	memset(diam, 0, sizeof diam);
	FOR (i, 0, N)
		FOR (j, 0, N)
			FOR (k, 0, N) {
				path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
				if (path[i][j] < 1e8)
					edge[i][j] = true;
			}

	FOR (i, 0, N)
		FOR (j, 0, N)
			if (edge[i][j])
				diam[i] = max(diam[i], path[i][j]);

	/* FOR (i, 0, N) { */
		/* FOR (j, 0, N) */
			/* printf("%6.2lf ", path[i][j]); */
			/* printf("%d", edge[i][j]); */
		/* printf("\n"); */
		/* printf("\n"); */
	/* } */

	/* FOR (i, 0, N) */
		/* cout << diam[i] << '\n'; */
		/* printf("%lf\n", diam[i]); */

	double ans = 1e9;
	FOR (i, 0, N)
		FOR (j, 0, N)
			if (!edge[i][j])
				ans = min(ans, diam[i]+diam[j]+
						sqrt(pow(pos[i].ft-pos[j].ft, 2)+pow(pos[i].sd-pos[j].sd, 2)));
	cout << fixed << setprecision(6) << ans << '\n';
	/* printf("%lf\n", ans); */

	/* printf("%lf %lf\n", diam[2], diam[6]); */

	return 0;
}
