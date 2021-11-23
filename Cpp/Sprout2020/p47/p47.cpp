#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

struct Node {
	ll val;
	Node *lt, *rt;
	Node *prt;

	Node(ll v) {
		val = v;
		prt = lt = rt = NULL;
	}

	Node* next(ll v) {
		return v < val ? lt : rt;
	}

	void setParent(Node *p) {
		prt = p;
	}

	void setChild(Node *c) {
		if (c->val < val)
			lt = c;
		else
			rt = c;
		c->setParent(this);
	}

	void removeChild(Node *c) {
		if (lt == c)
			lt = NULL;
		else if (rt == c)
			rt = NULL;
	}
};

struct BST {
	Node *head = new Node(1e18);

	void preOrder(Node *curr) {
		if (curr == NULL)
			return ;
		cout << curr->val << "(";
		preOrder(curr->lt);
		preOrder(curr->rt);
		cout << ")";
	}

	void preOrder() {
		preOrder(head->lt);
		cout << '\n';
	}

	void insert(ll v) {
		Node *curr = head;
		while (true) {
			if ((v < curr->val && curr->lt == NULL) || 
				(v > curr->val && curr->rt == NULL))
				curr->setChild(new Node(v));
			else if (v == curr->val)
				break;;
			curr = curr->next(v);
		}
	}

	bool find(ll v) {
		Node *curr = head;
		while (curr != NULL) {
			if (curr->val == v)
				return true;
			curr = curr->next(v);
		}
		return false;
	}

	void remove(ll v) {
		Node *tar = head;
		while (tar != NULL) {
			if (tar->val == v)
				break;
			tar = tar->next(v);
		}
		if (tar == NULL)
			return ;

		/* cout << tar->val; */
		
		if (tar->lt == NULL && tar->rt == NULL) {
			tar->prt->removeChild(tar);
			delete tar;
		}
		else if (tar->lt != NULL && tar->rt == NULL) {
			tar->prt->setChild(tar->lt);
			delete tar;
		} else if (tar->lt == NULL && tar->rt != NULL) {
			tar->prt->setChild(tar->rt);
			delete tar;
		} else {
			Node *succ = tar->lt;
			while (succ->rt != NULL)
				succ = succ->rt;
			tar->val = succ->val;
			if (succ->lt != NULL)
				succ->prt->setChild(succ->lt);
			else
				succ->prt->removeChild(succ);
			delete succ;
		}

	}
} bst;

ll N, t;
string com;

ll ans, ansa, ansb;

void update(ll p, ll v) {
	if (v < ans) {
		ans = v;
		ansa = p;
		ansb = 1e18;
	} else if (v == ans && p != ansa) {
		ansb = p;
		if (ansa > ansb)
			swap(ansa, ansb);
	}
}

void query(ll v) {
	Node *curr = bst.head;
	ll tmp;
	while (curr != NULL) {
		if (curr->lt != NULL) {
			tmp = curr->lt->val;
			update(tmp, abs(v-tmp));
		}
		if (curr->rt != NULL) {
			tmp = curr->rt->val;
			update(tmp, abs(v-tmp));
		}
		tmp = curr->val;
		update(tmp, abs(v-tmp));

		curr = curr->next(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> com >> t;
		if (com == "insert")
			bst.insert(t);
		else if (com == "delete")
			bst.remove(t);
		else if (com == "query") {
			ans = ansb = 1e18;
			query(t);

			cout << ansa;
			if (ansb < 1e18)
				cout << ' ' << ansb;
			cout << "\n";
		}
	}

	/* bst.preOrder(); */

	return 0;
}
