#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

struct Space {
	int x, y, val;
	Space(int _x, int _y, int _val):
		x(_x), y(_y), val(_val) {}
};

string str;
vector<string> ans;

vector<Space> spaces; 
bool row[9][9], col[9][9], blk[3][3][9];

void setNum(int x, int y, int num, bool b) {
	row[x][num] = b;
	col[y][num] = b;
	blk[x/3][y/3][num] = b;
}

bool valid(int x, int y, int num) {
	return !row[x][num] && !col[y][num] && !blk[x/3][y/3][num];
}

void solve(int d) {
	if (d == spaces.size()) {
		string tmp = str;
		int p = 0;
		FOR (i, 0, 81)
			if (tmp[i] == '.') {
				tmp[i] = spaces[p].val+'1';
				p++;
			}
		ans.pb(tmp);

		return ;
	}

	int x = spaces[d].x, y = spaces[d].y;
	FOR (i, 0, 9)
		if (valid(x, y, i)) {
			spaces[d].val = i;
			setNum(x, y, i, true);
			solve(d+1);
			setNum(x, y, i, false);
		}
	return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (true) {
		cin >> str;
		if (str == "end") break;

		FOR (i, 0, 9) memset(row[i], 0, sizeof row[i]);
		FOR (i, 0, 9) memset(col[i], 0, sizeof col[i]);
		FOR (i, 0, 3) FOR (j, 0, 3)
			memset(blk[i][j], 0, sizeof blk[i][j]);
		
		spaces.clear();
		bool v = true;
		FOR (i, 0, 9)
			FOR (j, 0, 9) {
				int num = str[i*9+j]-'1';
				if (num == '.'-'1')
					spaces.pb(Space(i, j, 0));
				else if (valid(i, j, num))
					setNum(i, j, num, true);
				else
					v = false;
			}
		
		ans.clear();
		if (v) solve(0);
		if (v && ans.size() > 0) {
			sort(ans.begin(), ans.end());
			cout << ans[0] << '\n';
		} else
			cout << "No solution.\n";
	}

    return 0;
}
