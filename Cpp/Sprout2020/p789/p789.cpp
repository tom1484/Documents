#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a-1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int N;
int arr[100005], tmp[100005];
vector<int> prob;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N > 1) {
		prob.pb(N);
		N = (N+(N&1))/2;
	}
	prob.pb(1);
	reverse(prob.begin(), prob.end());

	arr[0] = 1;
	int L = 1, s;
	FOR (i, 0, prob.size()-1) {
		FOR (j, 0, L) {
			tmp[j] = arr[j]*2-1;
			tmp[L+j] = arr[j]*2;
		}

		int k = 0;
		FOR (j, 0, 2*L) {
			if (prob[i+1] % 2 && tmp[j] == 2*L)
				continue;
			arr[k++] = tmp[j];
		}
		L = prob[i+1];
	}

	FOR (i, 0, L)
		cout << arr[i] << ' ';

    return 0;
}
