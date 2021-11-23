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
	int x, ad, ch;
	Node *lt, *rt;

	void change(int v) {
		x = v;
		ad = 0;
		ch = v;
	}

	void add(int v) {
		x += v;
		ad += v;
	}
};

const int maxn = 1e5 + 5;

int N, Q, cnt = 0;
int arr[maxn];
Node *head = new Node();

void build(Node*, int, int);
void modify(Node*, int, int, int, int, int, bool);
void add(Node*, int, int, int, int, int);
void change(Node*, int, int, int, int, int);
int query(Node*, int, int, int, int);
void push(Node*, int, int, int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	FOR (i, 0, N)
		cin >> arr[i];
	build(head, 0, N);

	int c, a, b, t;
	while (Q--) {
		cin >> c >> a >> b;
		if (c == 1) {
			cin >> t;
			modify(head, a - 1, b, 0, N, t, false);
		}
		else if (c == 3) {
			cin >> t;
			modify(head, a - 1, b, 0, N, t, true);
		}
		else 
			cout << query(head, a - 1, b, 0, N) << '\n';
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

void modify(Node *s, int a, int b, int l, int r, int v, bool flag) {

	if (a <= l && b >= r) {
		if (flag)
			s->change(v);
		else
			s->add(v);
		return ;
	}

	int m = (l + r) / 2;
	push(s, l, m, r);

	Node *lt = s->lt;
	Node *rt = s->rt;

	if (a < m)
		modify(lt, a, b, l, m, v, flag);
	if (m < b)
		modify(rt, a, b, m, r, v, flag);

	s->x = max(lt->x, rt->x);

}

int query(Node *s, int a, int b, int l, int r) {

	int m = (l + r) / 2;
	push(s, l, m, r);

	if (a <= l && b >= r)
		return s->x;

	Node *lt = s->lt;
	Node *rt = s->rt;
	
	int res = 0;
	if (a < m) 
		res = max(res, query(lt, a, b, l, m));
	if (b > m) 
		res = max(res, query(rt, a, b, m, r));

	return res;
}

void push(Node *s, int l, int m, int r) {
	
	if (r - l == 1) {
		s->ad = s->ch = 0;
		return ;
	}

	Node *lt = s->lt;
	Node *rt = s->rt;
	
	if (s->ch) {
		lt->change(s->ch);
		rt->change(s->ch);
		s->ch = 0;
	}

	if (s->ad) {
		lt->add(s->ad);
		rt->add(s->ad);
		s->ad = 0;
	}

}
