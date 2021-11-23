/*
ID: angelus6
TASK: concom
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

#define cin fin
#define cout fout
ifstream fin("concom.in");
ofstream fout("concom.out");

#define NCOM 101

int owns[NCOM][NCOM];
int controls[NCOM][NCOM];

void addcontroller(int i, int j) {
    int k;

    if(controls[i][j])
        return;

    controls[i][j] = 1;

    for (k = 0; k < NCOM; k++)
        owns[i][k] += owns[j][k];

    for (k = 0; k < NCOM; k++)
        if(controls[k][i])
            addcontroller(k, j);

    for (k = 0; k < NCOM; k++)
        if(owns[i][k] > 50)
            addcontroller(i, k);
}

void addowner(int i, int j, int p) {
    int k;

    for (k = 0; k < NCOM; k++)
        if(controls[k][i])
            owns[k][j] += p;

    for (k = 0; k < NCOM; k++)
        if(owns[k][j] > 50)
            addcontroller(k, j);
}

int main() {
    int i, j, n, a, b, p;

    for (i=0; i < NCOM; i++)
        controls[i][i] = 1;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b >> p;
        addowner(a, b, p);
    }

    for (i = 0; i < NCOM; i++)
		for (j = 0; j < NCOM;j++)
			if(i != j && controls[i][j])
				cout << i << ' '<< j << '\n';
	return 0;
}
