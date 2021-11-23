/*
ID: angelus6
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i ++)
#define RFOR(i, a, b) for (int i = a; i >= b; i --)
#define pb push_back
#define ft first
#define sd second
#define cin fin
#define cout fout

using ll = long long;
using pii = pair<int, int>;

vector<pii> edge;

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    cin >> n;

    int in, out;
    FOR (i, 0, n)
    {
        cin >> in >> out;
        edge.pb(make_pair(in, 1));
        edge.pb(make_pair(out, -1));
    }
    sort(edge.begin(), edge.end());

    int ans1 = 0, ans0 = 0;
    int con1 = 0, con0 = 0;
    int range, cnt = edge[0].sd;
    FOR (i, 1, edge.size())
    {
        range = edge[i].ft - edge[i - 1].ft;
        if (cnt > 0) con1 += range;
        if (cnt <= 0) con0 += range;
        if (range && cnt <= 0) con1 = 0;
        if (range && cnt > 0) con0 = 0;
        cnt += edge[i].sd;
        ans1 = max(ans1, con1);
        ans0 = max(ans0, con0);
    }

    cout << ans1 << ' ' << ans0 << endl;

    return 0;
}
