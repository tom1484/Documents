/*
ID: angelus6
TASK: dualpal
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

ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");

using ll = long long;
using pii = pair<int, int>;

string tobase(int n, int b)
{
    string str = "";
    while (n > 0)
    {
        str += char(n % b + '0');
        n /= b;
    }
    return str;
}

int valid(int n)
{
    int cnt = 0;
    FOR (b, 2, 11)
    {
        string res(tobase(n, b));
        string rev(res.rbegin(), res.rend());
        if (res == rev)
            cnt ++;
    }
    return cnt;
}

int main()
{
    int n, s;
    cin >> n >> s;

    int t = s + 1;
    while (n)
    {
        if (valid(t) >= 2)
        {
            cout << t << '\n';
            n --;
        }
        t ++;
    }


	return 0;
}
