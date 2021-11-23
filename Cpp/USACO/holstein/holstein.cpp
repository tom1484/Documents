/*
ID: angelus6
TASK: holstein
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
ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

int v;
int vit[25];

int g;
int sco[15][25];

bool valid(int* arr) {
	FOR (i, 0, v)
		if (arr[i] < vit[i])
			return false;
	return true;
}

int main() {
    
    cin >> v;
    FOR (i, 0, v)
    	cin >> vit[i];
    cin >> g;
    FOR (i, 0, g)
    	FOR (j, 0, v)
    		cin >> sco[i][j];

    int ans = 0, ansv = 1e9;
    int tmp[25];
    FOR (s, 1, (1<<g)) {
    	memset(tmp, 0, sizeof tmp);
    	int cnt = 0;
    	FOR (i, 0, g) {
    		if (s&(1<<i)) {
    			cnt++;
    			FOR (j, 0, v)
    				tmp[j] += sco[i][j];
    		}
    	}
    	if (valid(tmp) && cnt < ansv) {
    		ans = s;
    		ansv = cnt;
    	}
    }

    cout << ansv << ' ';
    vector<int> rec;    
    FOR (i, 0, g)
    	if (ans&(1<<i))
    		rec.pb(i+1);
    FOR (i, 0, rec.size())
    	cout << rec[i] << " \n"[i==rec.size()-1];

	return 0;
}
