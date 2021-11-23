/*
ID: angelus6
TASK: skidesign
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

ofstream fout ("skidesign.out");
ifstream fin ("skidesign.in");

using ll = long long;
using pii = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    FOR (i, 0, n)
        cin >> arr[i];

    int ans = 1e9, cnt;
    FOR (s, 17, 101)
    {
        cnt = 0;
        for (int x: arr)
        {
            if (x < s - 17)
                cnt += (s - 17 - x) * (s - 17 - x);
            if (x > s)
                cnt += (x - s) * (x - s);
        }
        ans = min(cnt, ans);
    }

    cout << ans << '\n';

	return 0;
}
