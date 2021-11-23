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

#define ninf 0xc0c0c0c0c0c0c0c0

struct Node {
	Node *lt, *rt;
	ll sum, ls, rs, s;
	Node(ll sum, ll ls, ll rs, ll s):
		sum(sum), ls(ls), rs(rs), s(s) {}
	Node():sum(0), ls(0), rs(0), s(0) {}
};

const int maxn = 1e5 + 1;

int N, Q;
ll arr[maxn];
Node *head = new Node();

void build(Node*, int, int);
Node _query(Node*, int, int, int, int);

ll query(int a, int b) {
	return _query(head, a, b, 0, N).s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	FOR (i, 0, N)
		cin >> arr[i];
	build(head, 0, N);

	int a, b;
	FOR (i, 0, Q) {
		cin >> a >> b;
		cout << max(0ll, query(a - 1, b)) << '\n';
	}

    return 0;
}

void build(Node *s, int l, int r) {
	
	if (r - l == 1) {
		*s = Node(arr[l], arr[l], arr[l], arr[l]);
		return ;
	}
	Node *lt = s->lt = new Node();
	Node *rt = s->rt = new Node();
	
	int m = (l + r) / 2;
	build(s->lt, l, m);
	build(s->rt, m, r);

	s->sum = lt->sum + rt->sum;
	s->s = max(lt->rs + rt->ls, max(lt->s, rt->s));
	s->ls = max(lt->ls, lt->sum + rt->ls);
	s->rs = max(rt->rs, rt->sum + lt->rs);

	return ;
}

Node _query(Node *s, int a, int b, int l, int r) {

	if (a <= l && r <= b)
		return *s;

	Node *lt = s->lt, *rt = s->rt;
	Node k, lk, rk;
	int m = (l + r) / 2;
	if (m >= b)
		return _query(s->lt, a, b, l, m);
	if (m <= a)
		return _query(s->rt, a, b, m, r);
	
	lk = _query(s->lt, a, b, l, m);
	rk = _query(s->rt, a, b, m, r);
	
	k.sum = lk.sum + rk.sum;
	k.s = max(lk.rs + rk.ls, max(lk.s, rk.s));
	k.ls = max(lk.ls, lk.sum + rk.ls);
	k.rs = max(rk.rs, rk.sum + lk.rs);

	return k;
}















