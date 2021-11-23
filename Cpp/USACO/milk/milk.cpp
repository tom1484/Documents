/*
ID: angelus6
TASK: milk
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

ofstream fout ("milk.out");
ifstream fin ("milk.in");

using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<pii> fac;

int main()
{
    cin >> n >> m;
    fac.resize(m);

    FOR (i, 0, m)
        cin >> fac[i].ft >> fac[i].sd;
    sort(fac.begin(), fac.end());

    int ans = 0;
    int i = 0, tot = 0, num;
    while (tot < n)
    {
        num = min(fac[i].sd, n - tot);
        tot += num;
        ans += num * fac[i].ft;
        fac[i].sd -= num;
        if (!fac[i].sd)
            i ++;
    }
    cout << ans << '\n';

	return 0;
}
