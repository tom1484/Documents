/*
ID: angelus6
TASK: friday
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

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y)
{
    if (y % 4 != 0) return false;
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return true;
}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int n;
    cin >> n;

    int ans[7] = {};
    int w = 1;
    FOR (year, 1900, 1900 + n)
    {
        FOR (month, 1, 13)
        {
            FOR (day, 1, days[month] + (month == 2 ? isLeap(year) : 0) + 1)
            {
                if (day == 13)
                    ans[(w - 6 + 7) % 7] ++;
                w ++;
                if (w > 7) w = 1;
            }
        }
    }

    FOR (i, 0, 7)
        cout << ans[i] << " \n"[i == 6];

	return 0;
}
