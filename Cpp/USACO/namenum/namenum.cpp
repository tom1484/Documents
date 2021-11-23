/*
ID: angelus6
TASK: namenum
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

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");

using ll = long long;
using pii = pair<int, int>;

char ch['9' + 1][3];
string str;

vector <string> dict;
int cnt = 0;

void solve(string name)
{
    if (name.size() == str.size())
    {
        if (*lower_bound(dict.begin(), dict.end(), name) == name)
        {
            cout << name << '\n';
            cnt ++;
        }
        return ;
    }

    FOR (i, 0, 3)
        solve(name + ch[str[name.size()]][i]);
}

int main()
{

    ifstream din ("dict.txt");
    string d;
    while (din >> d)
        dict.push_back(d);

    char c = 'A';
    FOR (i, '2', '9' + 1)
        FOR (j, 0, 3)
        {
            ch[i][j] = (c ++);
            if (c == 'Q') c ++;
        }

    cin >> str;
    solve("");
    if (!cnt)
        cout << "NONE\n";

	return 0;
}
