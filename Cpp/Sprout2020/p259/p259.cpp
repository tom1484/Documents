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

#define inf 500001

const int maxn = 2e6 + 1;

int N, Q;
int x[maxn << 2];
int lt[maxn << 2];
int rt[maxn << 2];

void build(int, int, int);
void modify(int, int, int, int, int, int, bool);
int query(int, int, int, int, int);
inline void pushdown(int);

inline void add(int id, int v) {
	lt[id] = max(lt[id], v);
	rt[id] = max(rt[id], v);
	x[id] = max(x[id], lt[id]);
}

inline void cut(int id, int v) {
	rt[id] = min(rt[id], v);
	lt[id] = min(lt[id], v);
	x[id] = min(x[id], rt[id]);
}

inline void update(int id, int v, int pl, int pr) {
	if (rt[id] < pl)
		lt[id] = rt[id] = pl;
	else if (lt[id] > pr)
		lt[id] = rt[id] = pr;
	else {
		lt[id] = max(lt[id], pl);
		rt[id] = min(rt[id], pr);
	}
	x[id] = max(x[id], lt[id]);
	x[id] = min(x[id], rt[id]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	build(1, 0, N);

	int c, a, b, v;
	while (Q--) {
		cin >> c >> a >> b >> v;
		modify(1, a, b + 1, 0, N, v, c - 1);
	}

	FOR (i, 0, N)
		cout << query(1, i, i + 1, 0, N) << '\n';
    
	return 0;
}

void build(int id, int l, int r) {
	
	x[id] = 0;
	lt[id] = 0, rt[id] = inf;

	if (r - l == 1)
		return ;

	int m = (l + r) / 2;
	build(id << 1, l, m);
	build(id << 1 | 1, m, r);

	return ;
}

void modify(int id, int a, int b, int l, int r, int v, bool flag) {

	if (a <= l && b >= r) {
		if (flag)
			cut(id, v);
		else
			add(id, v);
		return ;
	}

	int m = (l + r) / 2;
	pushdown(id);

	if (a < m)
		modify(id << 1, a, b, l, m, v, flag);
	if (m < b)
		modify(id << 1 | 1, a, b, m, r, v, flag);

}

int query(int id, int a, int b, int l, int r) {

	if (a <= l && b >= r) {
		x[id] = max(x[id], lt[id]);
		x[id] = min(x[id], rt[id]);
		return x[id];
	}

	int m = (l + r) / 2;
	pushdown(id);

	if (a < m)
		return query(id << 1, a, b, l, m);
	else
		return query(id << 1 | 1, a, b, m, r);

}

inline void pushdown(int id) {
	
	if (lt[id] > -1 || rt[id] < inf) {
		update(id << 1, x[id], lt[id], rt[id]);
		update(id << 1 | 1, x[id], lt[id], rt[id]);
		lt[id] = -1;
		rt[id] = inf;
	}

}





