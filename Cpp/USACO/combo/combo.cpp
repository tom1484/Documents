/*
ID: angelus6
TASK: combo
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i ++)
#define pb push_back
#define ft first
#define sd second
#define cin fin
#define cout fout

ofstream fout ("combo.out");
ifstream fin ("combo.in");

using ll = long long;
using pii = pair<int, int>;

int n;
int tar[2][3];

int main()
{
    cin >> n;
    FOR (i, 0, 2)
        FOR (j, 0, 3)
            cin >> tar[i][j];

    int dot = 1, ran1[5], ran2[5];
    vector<int> s(10);
    vector<int>::iterator it;
    FOR (i, 0, 3)
    {
        FOR (j, -2, 3)
        {
            ran1[j + 2] = (tar[0][i] + j + n) % n;
            if (!ran1[j + 2]) ran1[j + 2] = n;
            ran2[j + 2] = (tar[1][i] + j + n) % n;
            if (!ran2[j + 2]) ran2[j + 2] = n;
        }
        sort(ran1, ran1 + 5);
        it = set_intersection(ran1, ran1 + 5, ran2, ran2 + 5, s.begin());
        it = unique(s.begin(), s.end());
        dot *= it - s.begin() - 1;
    }

    cout << pow(min(n, 5), 3) * 2 - (dot > 0 ? dot : 0) << '\n';

	return 0;
}
