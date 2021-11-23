/*
ID: angelus6
TASK: gift1
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

map<string, int> account;
vector<string> person;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    cin >> n;

    string name;
    FOR (i, 0, n)
    {
        cin >> name;
        account[name] = 0;
        person.pb(name);
    }

    int tot, num, each;
    while (cin >> name)
    {
        cin >> tot >> num;
        if (!num) continue;

        each = tot / num;
        account[name] -= each * num;

        FOR (i, 0, num)
        {
            cin >> name;
            account[name] += each;
        }
    }

    for (string p: person)
        cout << p << ' ' << account[p] << endl;

	return 0;
}








