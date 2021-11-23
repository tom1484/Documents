/*
ID: angelus6
TASK: crypt1
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

ofstream fout ("crypt1.out");
ifstream fin ("crypt1.in");

using ll = long long;
using pii = pair<int, int>;

bool valid[10];

bool check(int n)
{
    while (n > 0)
    {
        if (!valid[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

void print(int n)
{
    int b = 1;
    while (b * 10 <= n)
        b *= 10;
    while (n > 0)
    {
        cout << ' ' << n / b;
        n = n % b;
        b /= 10;
    }
    cout << '\n';
}

int main()
{
    int n, t;
    cin >> n;

    memset(valid, 0, sizeof valid);
    FOR (i, 0, n)
    {
        cin >> t;
        valid[t] = true;
    }

    int cnt = 0;
    FOR (i, 100, 1000)
    {
        if (!check(i))
            continue;
        FOR (j, 10, 100)
        {
            if (!check(j))
                continue;
            int a = i * (j / 10);
            int b = i * (j % 10);
            if (a < 100 || a > 999 || b < 100 || b > 999)
                continue;
            if (!check(a) || !check(b))
                continue;
            if (i * j < 1000 || i * j > 9999 || !check(i * j))
                continue;
//            cout << "     ";
//            print(i);
//            cout << "    x  ";
//            print(j);
//            cout << "     ------\n";
//            cout << "     ";
//            print(b);
//            cout << "   ";
//            print(a);
//            cout << "  ---------\n";
//            cout << "   ";
//            print(i * j);
            cnt ++;
        }
    }
    cout << cnt << '\n';

	return 0;
}
