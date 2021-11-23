#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

const int maxn = 500005;

int T, N, X, Y, Z;
int A[maxn], B[maxn];
deque<int> deq;
priority_queue<int> Q;
int exist[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(exist, 0, sizeof exist);

	cin >> T;
	while (T--) {
		cin >> N >> X >> Y >> Z;
		FOR (i, 0, N)
			cin >> A[i];
		FOR (i, 0, N)
			cin >> B[i];
		
		int j = 0;
		int x = 0, y = 0, z = 0;
		int xz = 0, yz = 0, xyz = 0;
		deq.clear();
		while (!Q.empty())
			Q.pop();
		
		FOR (i, 0, N) {
			deq.pb(A[i]);
			Q.push(A[i]);
			exist[A[i]] = T + 1;
			while (true) {
				bool mod = false;
				if (!deq.empty()) {
					if (B[j] == Q.top()) {
						mod = true;
						if (i + 1 - j == 1)
							xyz++;
						else if (deq.front() == B[j])
							xz++;
						else if (deq.back() == B[j])
							yz++;
						else
							z++;
					} 
					else if (B[j] == deq.front()) {
						x++;
						mod = true;
					}
					else if (B[j] == deq.back()) {
						y++;
						mod = true;
					}
				}
				if (!mod)
					break;
				exist[B[j]] = 0;
				j++;
				while (!deq.empty() && exist[deq.front()] != T + 1)
					deq.pop_front();
				while (!deq.empty() && exist[deq.back()] != T + 1)
					deq.pop_back();
				while (!Q.empty() && exist[Q.top()] != T + 1)
					Q.pop();
			}
		}

		int r;
		if (x < X) {
			r = min(xz, X - x);
			x += r;
			xz -= r;
			if (x < X) {
				r = min(xyz, X - x);
				x += r;
				xyz -= r;
			}
		}
		if (y < Y) {
			r = min(yz, Y - y);
			y += r;
			yz -= r;
			if (y < Y) {
				r = min(xyz, Y - y);
				y += r;
				xyz -= r;
			}
		}
		if (z < Z) {
			r = min(xz, Z - z);
			z += r;
			xz -= r;
			if (z < Z) {
				r = min(yz, Z - z);
				z += r;
				yz -= r;
				if (z < Z) {
					r = min(xyz, Z - z);
					z += r;
					xyz -= r;
				}
			}
		}

		if (x == X && y == Y && z == Z && xz + yz + xyz == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
		/* cout << x << ' ' << y << ' ' << z << '\n'; */
	}

    return 0;
}
