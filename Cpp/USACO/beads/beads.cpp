/*
ID: angelus6
TASK: beads
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

using ll = long long;
using pii = pair<int, int>;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n;
    cin >> n;
    string str;
    cin >> str;

    int ans = 0, cnt, p;
    char first;
    bool met;
    FOR (i, 0, n)
    {
        cnt = 0;

        first = str[i];
        p = (i + n) % n;
        met = false;
        while (cnt < n && (str[p] == 'w' || str[p] == first))
        {
            if (str[p] != 'w') met = true;
            p = (p - 1 + n) % n;
            if (!met && str[p] != 'w')
                first = str[p];
            cnt ++;
        }

        first = str[(i + 1) % n];
        p = (i + 1) % n;
        met = false;
        while (cnt < n && (str[p] == 'w' || str[p] == first))
        {
            if (str[p] != 'w') met = true;
            p = (p + 1) % n;
            if (!met && str[p] != 'w')
                first = str[p];
            cnt ++;
        }
        ans = max(cnt, ans);
//        cout << i << ' ' << cnt << '\n';
    }
    cout << ans << endl;

	return 0;
}
