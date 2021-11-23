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
	int x, t;
	Node *lt, *rt;
	Node(): x(0), t(0) {}
};

const int maxn = 1e5 + 5;

int N, Q;
int arr[maxn];
Node *head = new Node();

void build(Node*, int, int);
void add(Node*, int, int, int, int, int);
int query(Node*, int, int, int, int);
void push(Node*);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	FOR (i, 0, N)
		cin >> arr[i];
	
	build(head, 0, N);

	int c, a, b, v;
	while (Q--) {
		cin >> c >> a >> b;
		if (c == 1) {
			cin >> v;
			add(head, a - 1, b, 0, N, v);
		} 
		else {
			cout << query(head, a - 1, b, 0, N) << "\n";
		}
	}

    return 0;
}

void build(Node *s, int l, int r) {
	
	if (r - l == 1) {
		s->x = arr[l];
		return ;
	}

	int m = (l + r) / 2;
	s->lt = new Node();
	build(s->lt, l, m);
	s->rt = new Node();
	build(s->rt, m, r);
	
	s->x = max(s->lt->x, s->rt->x);

	return ;
}

void push(Node *s) {
	
	Node *lt = s->lt;
	Node *rt = s->rt;

	if (s->t) {
		lt->x += s->t;
		lt->t += s->t;
		rt->x += s->t;
		rt->t += s->t;
		s->t = 0;
	}
}

void add(Node *s, int a, int b, int l, int r, int v) {

	if (a <= l && b >= r) {
		s->x += v;
		s->t += v;
		return ;
	}

	Node *lt = s->lt;
	Node *rt = s->rt;
	push(s);

	int m = (l + r) / 2;
	if (a < m)
		add(lt, a, b, l, m, v);
	if (m < b)
		add(rt, a, b, m, r, v);

	s->x = max(lt->x, rt->x);
}

int query(Node *s, int a, int b, int l, int r) {
	
	if (a <= l && b >= r)
		return s->x;

	Node *lt = s->lt;
	Node *rt = s->rt;
	push(s);

	int res = 0;
	int m = (l + r) / 2;
	if (a < m) 
		res = max(res, query(lt, a, b, l, m));
	if (b > m) 
		res = max(res, query(rt, a, b, m, r));

	return res;
}






