/*
ID: angelus6
TASK: barn1
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

ofstream fout ("barn1.out");
ifstream fin ("barn1.in");

using ll = long long;
using pii = pair<int, int>;

bool arr[205];
vector<int> sec;

int main()
{
    int M, S, C, t;
    cin >> M >> S >> C;

    memset(arr, 0, sizeof arr);
    FOR (i, 0, C)
    {
        cin >> t;
        arr[-- t] = 1;
    }
    FOR (i, 0, S)
    {
        if (!i || arr[i - 1] || (i == S - 1 && arr[i]))
            sec.pb(0);
        if (!arr[i])
            sec[sec.size() - 1] ++;
    }
//    for (int x: sec)
//        cout << x << '\n';

    int ans = S, cnt = 1;
    ans -= sec[0] + sec.back();
    sort(sec.begin() + 1, sec.end() - 1, [](int &a, int &b)
         {
             return a > b;
         });

    while (cnt < min(M, (int)sec.size() - 1))
        ans -= sec[cnt ++];
    cout << ans << '\n';

	return 0;
}
