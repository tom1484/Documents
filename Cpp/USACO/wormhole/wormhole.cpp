/*
ID: angelus6
TASK: wormhole
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
#define ninf 0xc0c0c0c0

ofstream fout ("wormhole.out");
ifstream fin ("wormhole.in");

using ll = long long;
using pii = pair<int, int>;

struct Hole
{
    int idx, x, y;

    bool operator <(Hole &t)
    {
        return (y != t.y ? y < t.y : x < t.x);
    }
};

int n, ans = 0;
vector<Hole> hole;
vector<int> rhole;

int combo[12];

bool valid()
{
    bool vis1[n], vis2[n];
    memset(vis1, 0, sizeof vis1);
    FOR (i, 0, n)
    {
        if (vis1[i])
            continue;
        vis1[i] = true;
        int s = i;
        memset(vis2, 0, sizeof vis2);
        while (true)
        {
            if (vis2[s])
                return true;
            vis2[s] = true;
            s = combo[s];
            if (rhole[s] < 0)
                break;
            else
                s = rhole[s];
        }
    }
    return false;
}

void solve(int p)
{
    if (p >= n)
    {
        if (valid())
            ans ++;
        return ;
    }

    int s = 0;
    while (combo[s] >= 0)
        s ++;

    FOR (i, s + 1, n)
    {
        if (combo[i] >= 0)
            continue;
        combo[s] = i;
        combo[i] = s;
        solve(p + 2);
        combo[s] = ninf;
        combo[i] = ninf;
    }
}

int main()
{
    cin >> n;
    hole.resize(n);
    rhole.resize(n);

    FOR (i, 0, n)
    {
        hole[i].idx = i;
        cin >> hole[i].x >> hole[i].y;
    }
    sort(hole.begin(), hole.end());

    FOR (i, 0, n)
    {
        if (i == n - 1 || hole[i].y != hole[i + 1].y)
            rhole[hole[i].idx] = -1;
        else
            rhole[hole[i].idx] = hole[i + 1].idx;
    }

    memset(combo, ninf, sizeof combo);
    solve(0);
    cout << ans << '\n';

	return 0;
}
