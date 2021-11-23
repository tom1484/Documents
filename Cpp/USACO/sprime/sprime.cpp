/*
ID: angelus6
TASK: sprime
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

int n;
int ptable[10000];
vector<int> prime;
vector<int> sprime[8];

bool isprime(int i) {
	for (int j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++) {
		if (!(i%prime[j]))
			return false;
	}
	return true;
}

int main() {

	memset(ptable, 0, sizeof ptable);
	FOR (i, 2, 10000) {
		if (!ptable[i]) {
			prime.pb(i);
			for (int j = i*2; j < 10000; j += i)
				ptable[j] = true;
		}
	}

	for (int i = 0; prime[i] < 10; i++)
		sprime[0].pb(prime[i]);
	
	cin >> n;

	FOR (i, 0, n-1) {
		for (int p: sprime[i]) {
			FOR (j, 1, 10)
				if (isprime(p*10+j))
					sprime[i+1].pb(p*10+j);
		}
	}

	for (int i = 0; i < sprime[n-1].size(); i++)
		cout << sprime[n-1][i] << "\n";

	return 0;
}
