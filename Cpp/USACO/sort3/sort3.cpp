/*
ID: angelus6
TASK: sort3
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("sort3.out");
ifstream fin ("sort3.in");

int n;
int arr[1005], cnt[4] = {};
vector<int> to[4][4];

int getRangeIdx(int idx) {
	int rt = cnt[1], res = 1;
	while (rt <= idx)
		res++, rt += cnt[res];
	return res;
}

int main() {
	
	cin >> n;
	FOR (i, 0, n) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	FOR (i, 0, n)
		to[getRangeIdx(i)][arr[i]].pb(i);

	// FOR (i, 1, 4) FOR (j, 1, 4) if (i != j){
	// 	for (int x: to[i][j])
	// 		cout << x << ' ';
	// 	cout << '\n';
	// }

	bool sp = true;
	int ans = 0;
	while (sp) {
		sp = false;
		FOR (i, 1, 4) FOR (j, i+1, 4) if (!to[i][j].empty()) {
			if (!to[j][i].empty()) {
				sp = true;
				ans++;
				swap(arr[to[i][j].back()], arr[to[j][i].back()]);
				to[i][j].pop_back(), to[j][i].pop_back();
			}
		}
		if (!sp) {
			FOR (i, 1, 4) FOR (j, i+1, 4) if (!sp && !to[i][j].empty()) {
				sp = true;
				ans++;
				swap(arr[to[i][j].back()], arr[to[j][6-i-j].back()]);
				to[i][6-i-j].pb(to[i][j].back());
				to[i][j].pop_back(), to[j][6-i-j].pop_back();
			}
		}
	}

//	FOR (i, 1, 4) FOR (j, 1, 4) if (i != j){
//		while (!to[i][j].empty()) {
//			cout << to[i][j].top() << ' ';
//			to[i][j].pop();
//		}
//		cout << '\n';
//	}

	// FOR (i, 0, n)
	// 	cout << arr[i] << ' ';
	// cout << '\n';
	cout << ans << '\n';

	return 0;
}
