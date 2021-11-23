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
	int val;
	Node *next = NULL;

	Node() {}
	Node(int v): val(v) {}
};

int n, m;
Node *head[105];
Node *tail[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	string com;

	FOR (i, 1, n+1) {
		head[i] = new Node();
		tail[i] = head[i];
	}

	int i, j, id;
	while (cin >> com) {
		if (com == "ADD") {
			cin >> i >> id;
			tail[i]->next = new Node(id);
			tail[i] = tail[i]->next;
		} else if (com == "LEAVE") {
			cin >> i;
			if (head[i]->next == NULL)
				cout << "queue " << i << " is empty!\n";
			else {
				head[i]->next = head[i]->next->next;
				if (head[i]->next == NULL)
					tail[i] = head[i];
			}
		} else {
			cin >> i >> j;
			if (head[i]->next != NULL) {
				tail[j]->next = head[i]->next;
				tail[j] = tail[i];
			}
			head[i] = new Node();
			tail[i] = head[i];
		}
	}

	FOR (i, 1, n+1) {
		cout << "queue " << i << ": ";
		if (head[i]->next == NULL)
			cout << "empty\n";
		else {
			Node *curr = head[i]->next;
			while (true) {
				cout << curr->val;
				if (curr->next != NULL)
					cout << ' ';
				else
					break;
				curr = curr->next;
			}
			cout << '\n';
		}
	}

    return 0;
}
