/*
ID: angelus6
TASK: palsquare
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

ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

using ll = long long;
using pii = pair<int, int>;

int base;

string trans(int n)
{
    string res = "";
    int b = base;
    while (n > 0)
    {
        res = char(n % b + '0') + res;
        if (res[0] > '9')
            res[0] += 7;
        n /= b;
    }
    return res;
}

bool valid(string s)
{
    FOR (i, 0, s.size() / 2)
        if (s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

int main()
{
    cin >> base;
    FOR (i, 1, 301)
    {
        string a = trans(i);
        string b = trans(i * i);
        if (valid(b))
            cout << a << ' ' << b << '\n';
    }

	return 0;
}
