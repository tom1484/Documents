#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

string str[2];
bool valid[2] = {1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str[0];
	str[1] = str[0];

	reverse(str[1].begin(), str[1].end());
	
	FOR (i, 0, 2) {
		int n = stoi(str[i]);
		FOR (j, 2, n) {
			if (n % j == 0)
				valid[i] = 0;
		}
		if (!valid[0])
			continue;
	}

	if (valid[0] && valid[1])
		cout << "IS VIP";
	else
		cout << "NOT VIP";

    return 0;
}
