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
	int x[3] = {};
	int len, ch = 0, ad = 0;
	Node *lt, *rt;

	void pushup() {
		x[0] = lt->x[0] + rt->x[0];
		x[1] = lt->x[1] + rt->x[1];
		x[2] = lt->x[2] + rt->x[2];
	}
	void turn() {
		swap(x[0], x[2]);
		swap(x[1], x[2]);
	}
	void add() {
		turn();
		ad += 1;
		ad %= 3;
	}
	void reset() {
		x[0] = len;
		x[1] = x[2] = 0;
		ad = 0, ch = 1;
	}
};

const int maxn = 1e6 + 5;

int N, Q;
Node *head = new Node();

void build(Node*, int, int);
void add(Node*, int, int, int, int);
void reset(Node*, int, int, int, int);
int query(Node*, int, int, int, int);
void pushdown(Node*, int, int, int);

void check(Node *s, int l, int r) {
	cout << l << ' ' << r << '\n';
	FOR (i, 0, 3)
		cout << s->x[i] << ' ';
	cout << '\n';
	cout << s->ad << ' ' << s->ch << "\n\n";

	if (r - l == 1)
		return ;

	int m = (l + r) / 2;
	check(s->lt, l, m);
	check(s->rt, m, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	build(head, 0, N);

	string c;
	int a, b;
	while (Q--) {
		cin >> c >> a >> b;
		if (c == "TURN") 
			add(head, a - 1, b, 0, N);
		else if (c == "RESET") 
			reset(head, a - 1, b, 0, N);
		else
			cout << query(head, a - 1, b, 0, N) << '\n';
	}

    return 0;
}

void build(Node *s, int l, int r) {
	
	s->len = r - l;
	if (r - l == 1) {
		s->x[0] = 1;
		return ;
	}

	int m = (l + r) / 2;
	s->lt = new Node();
	build(s->lt, l, m);
	s->rt = new Node();
	build(s->rt, m, r);
	
	s->x[0] = s->len;

	return ;
}

void add(Node *s, int a, int b, int l, int r) {

	if (a <= l && b >= r) {
		s->add();
		return ;
	}

	int m = (l + r) / 2;
	pushdown(s, l, m, r);
	
	Node *lt = s->lt;
	Node *rt = s->rt;
	
	if (a < m)
		add(lt, a, b, l, m);
	if (m < b)
		add(rt, a, b, m, r);

	s->pushup();

}

void reset(Node *s, int a, int b, int l, int r) {

	if (a <= l && b >= r) {
		s->reset();
		return ;
	}
	
	int m = (l + r) / 2;
	pushdown(s, l, m, r);

	Node *lt = s->lt;
	Node *rt = s->rt;

	if (a < m)
		reset(lt, a, b, l, m);
	if (m < b)
		reset(rt, a, b, m, r);

	s->pushup();

}

int query(Node *s, int a, int b, int l, int r) {
	
	if (a <= l && b >= r)
		return s->x[0];
	
	int m = (l + r) / 2;
	pushdown(s, l, m, r);

	Node *lt = s->lt;
	Node *rt = s->rt;
	int res = 0;
	if (a < m) 
		res += query(lt, a, b, l, m);
	if (b > m) 
		res += query(rt, a, b, m, r);

	return res;
}

void pushdown(Node *s, int l, int m, int r) {
	
	if (s->len == 1) {
		s->ad = s->ch = 0;
		return ;
	}

	Node *lt = s->lt;
	Node *rt = s->rt;
	
	if (s->ch) {
		lt->reset();
		rt->reset();
		s->ch = 0;
	}

	if (s->ad) {
		FOR (i, 0, s->ad) {
			lt->add();
			rt->add();
		}
		s->ad = 0;
	}

}

