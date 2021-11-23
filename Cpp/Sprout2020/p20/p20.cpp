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

int T = 1, g, n, t;
int group[1000005];
int gpos[1005];
queue<int>* gqueue[1000005];
int front, back;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> g) {
		cout << "Line #" << T++ << '\n';

		memset(group, 0, sizeof group);
		FOR (i, 1, g+1) {
			cin >> n;
			FOR (j, 0, n) {
				cin >> t;
				group[t] = i;
			}
		}
		
		memset(gpos, 0, sizeof gpos);
		front = 1, back = 1;

		string com;
		while (cin >> com) {
			if (com == "ENQUEUE") {
				cin >> t;
				g = group[t];
				if (!g || !gpos[g] || gqueue[gpos[g]]->empty()) {
					gpos[g] = back;
					gqueue[back++] = new queue<int>;
				}
				gqueue[gpos[g]]->push(t);
			}
			else if (com == "DEQUEUE") {
				while (front < back && gqueue[front]->empty())
					front++;
				cout << gqueue[front]->front() << '\n';
				gqueue[front]->pop();
			}
			else
				break;

		}
	}

	return 0;
}
