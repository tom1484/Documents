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

struct Node {
	int x, t = 0;
	Node *lt, *rt;
};

const int maxn = 1e6 + 5;

int N, Q;
int arr[maxn];
Node *head = new Node();

void build(Node*, int, int);
int _query(Node*, int, int, int, int);
void _modify(Node*, int, int, int, int );

int query(int a, int b) {
	return _query(head, a, b, 0, N);
}

void modify(int a, int v) {
	_modify(head, a, 0, N, v);
}

int main() {
	/* ios::sync_with_stdio(false); */
	/* cin.tie(NULL); */

	cin >> Q >> N;
	FOR (i, 0, N)
		cin >> arr[i];
	
	build(head, 0, N);
	
	int c, a, b;
	while (Q--) {
		cin >> c >> a >> b;
		if (c == 2)
			modify(a, b);
		else {
			cout << query(a, b + 1) << '\n';
		}
	}

    return 0;
}

void build(Node *s, int lt, int rt) {
	
	if (rt - lt == 1) {
		s->x = arr[lt];
		return ;
	}

	int mid = (lt + rt) / 2;
	s->lt = new Node();
	build(s->lt, lt, mid);
	s->rt = new Node();
	build(s->rt, mid, rt);
	
	s->x = min(s->lt->x, s->rt->x);

	return ;
}

void _modify(Node *s, int a, int lt, int rt, int v) {
	if (rt - lt == 1) {
		s->x = v;
		return ;
	}

	int mid = (lt + rt) / 2;
	if (mid > a)
		_modify(s->lt, a, lt, mid, v);
	if (mid <= a)
		_modify(s->rt, a, mid, rt, v);

	s->x = min(s->lt->x, s->rt->x);
}

int _query(Node *s, int a, int b, int lt, int rt) {
	
	if (a <= lt && b >= rt)
		return s->x;

	int res = 1e9;
	int mid = (lt + rt) / 2;
	if (a < mid)
		res = min(res, _query(s->lt, a, b, lt, mid));
	if (b > mid)
		res = min(res, _query(s->rt, a, b, mid, rt));

	return res;
}






