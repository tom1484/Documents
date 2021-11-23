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

struct Node {
	int val;
	Node *prev = NULL, *next = NULL;

	Node(int v): val(v) {}
} *head = new Node(0), *tail = new Node(0);

Node* pos[100005];

int n, m;

int main () {
	/* ios::sync_with_stdio(false); */
	/* cin.tie(NULL); */

	cin >> n >> m;

	pos[0] = head;
	pos[n+1] = tail;
	FOR (i, 1, n+1) {
		pos[i] = new Node(i);
		pos[i]->prev = pos[i-1];
		pos[i-1]->next = pos[i];
	}
	pos[n]->next = tail;
	tail->prev = pos[n];

	int a, b;
	while (m--) {
		cin >> a >> b;
		/* cout << a << ' ' << b << '\n'; */
		if (a) {
			Node *p = pos[b]->prev;
			if (p == head)
				continue;

			pos[b]->next->prev = p;
			p->prev->next = pos[b];

			p->next = pos[b]->next;
			pos[b]->next = p;
			pos[b]->prev = p->prev;
			p->prev = pos[b];
		} else {
			pos[b]->prev->next = pos[b]->next;
			pos[b]->next->prev = pos[b]->prev;
		}
	}

	Node *curr = head->next;
	while (curr != tail) {
		cout << curr->val << " \n"[curr->next==tail];
		curr = curr->next;
	}


	return 0;
}
