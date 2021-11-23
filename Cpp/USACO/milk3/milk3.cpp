/*
ID: angelus6
TASK: milk3
LANG: C++
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");

struct Status
{
    int val[3];
    Status(int x, int y, int z)
    {
        val[0] = x;
        val[1] = y;
        val[2] = z;
    }
    Status() {}
};

bool vis[21][21][21] = {};
queue<Status> q;
vector<int> ans;

bool exist(Status s)
{
    return vis[s.val[0]][s.val[1]][s.val[2]];
}

bool add(Status s)
{
    vis[s.val[0]][s.val[1]][s.val[2]] = true;
}

int main()
{
    int cap[3];
    cin >> cap[0] >> cap[1] >> cap[2];

    q.push(Status(0, 0, cap[2]));
    while (!q.empty())
    {
        Status now = q.front();
        q.pop();

        FOR (i, 0, 2)
            FOR (j, 0, 2)
                if (i != j)
                {
                    int v = min(now.val[i], cap[j]-now.val[j]);
                    int t[3] = {now.val[0], now.val[1], now.val[2]};
                    t[i] -= v, t[j] += v;
                    Status s = Status(t[0], t[1], t[2]);
                    if (!exist(s))
                    {
                        q.push(s);
                        add(s);
                        if (!s.val[0])
                            ans.push_back(s.val[2]);
                    }
                }
    }

    sort(ans.begin(), ans.end());
    int e = unique(ans.begin(), ans.end())-ans.begin();
    FOR (i, 0, e-1)
        cout << ans[i] << " \n"[i == e-1];
//    for (int x: ans)
//        cout << x << ' ';

	return 0;
}
