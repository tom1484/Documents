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
	int cnt = 0;
	Node *ch[26] = {};
};

int N, M;
string str;
Node *head = new Node();

void add();
int query();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	FOR (i, 0, N) {
		cin >> str;
		add();
	}

	FOR (j, 0, M) {
		cin >> str;
		cout << query() << '\n';
	}

    return 0;
}

void add() {

	int x, d = 0;
	Node *curr = head;
	while (d < str.size()) {
		x = str[d] - 'a';
		if (curr->ch[x] == NULL)
			curr->ch[x] = new Node();
		curr = curr->ch[x];
		d++;
	}
	curr->cnt += 1;

}

int query() {

	int x, d = 0;
	Node *curr = head;
	while (d < str.size()) {
		x = str[d] - 'a';
		if (curr->ch[x] == NULL)
			return 0;
		curr = curr->ch[x];
		d++;
	}
	return curr->cnt;

}



