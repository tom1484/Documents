/*
ID: angelus6
TASK: prefix
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("prefix.in");
ofstream fout("prefix.out");

struct Node {
	char c;
	int flag = 0;
	Node* child[26];
	Node(char c): c(c) {}
	Node() {}
} *root = new Node();

bool dp[200005] = {};

int main() {

	string s;
	while (cin >> s) {
		if (s == ".")
			break;
		Node* curr = root;
		for (int i = s.size()-1; i >= 0; i--) {
			if (curr->child[s[i]-'A'] == NULL)
				curr->child[s[i]-'A'] = new Node(s[i]);
			curr = curr->child[s[i]-'A'];
		}
		curr->flag = 1;
	}

	s = "";
	string tmp;
	while (cin >> tmp)
		s += tmp;

	int ans = 0;
	dp[0] = true;
	FOR (i, 0, s.size()) {
		Node* curr = root;
		for (int j = i; j >= 0 && curr->child[s[j]-'A'] != NULL; j--) {
			curr = curr->child[s[j]-'A'];
			if (curr->flag) {
				dp[i+1] = max(dp[i+1], dp[j]); 
			}
		}
		if (dp[i+1])
			ans = max(ans, i+1);
	}
	cout << ans << '\n';


	return 0;
}
