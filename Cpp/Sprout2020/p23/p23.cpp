#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (uint i = a; i < b; i++)
#define RFOR(i, a, b) for (uint i = a; i > b; i--)

#define pb push_back
#define ft first
#define sd second

int sA[5000], sB[5000];
int A = 0, B = 0;

void solve(int N, int order[]) {
	FOR (i, 0, N) {
		sA[A++] = i+1;
		push_train();
	}

	FOR (i, 0, N) {
		while (A) {
			sB[B++] = sA[--A];
			move_station_1_to_2();
			if (sB[B-1] == order[i]) {
				B--;
				pop_train();
			}
		}
		while (B) {
			sA[A++] = sB[--B];
			move_station_2_to_1();
		}
	}
}
