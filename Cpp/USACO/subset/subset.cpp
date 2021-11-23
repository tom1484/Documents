/*
ID: angelus6
TASK: subset
LANG: C++
*/
// #pragma GCC optimize("O3", "unroll-loops")
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
ofstream fout ("subset.out");
ifstream fin ("subset.in");

int N;
int dp[40][781] = {};

int main() {
    
    cin >> N;
    dp[1][390+1] = 1, dp[1][390-1];
    FOR (i, 2, 40) {
    	FOR (j, 0, 781) {
    		if (j+i < 781)
    			dp[i][j] += dp[i-1][j+i];
    		if (j-i >= 0)
    			dp[i][j] += dp[i-1][j-i];
    	}
    }
    cout << dp[N][390] << '\n'; 

	return 0;
}
