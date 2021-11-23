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

int main() {
    /* ios::sync_with_stdio(false); */
    /* cin.tie(NULL); */

	ll A, B, C, D;
	ll M, S, T;
	cin >> A >> B >> C >> D;
	cin >> M >> S >> T;

	bool valid = false;
	ll f = 1e9, l = 0;
	FOR (i, 0, T+1) {
		ll fuel = M+i*D;
		ll time = i+min(T-i, fuel/C);
		ll dis = B*(time-i) + A*(T-time);

		time -= max((ll)0, B*(time-i)-S)/B;
		ll resS = max((ll)0, S-B*(time-i));
		time += resS/A + (resS%A != 0);
	
		if (dis >= S) {
			valid = true;
			f = min(f, time);
		}
		else
			l = max(l, dis);
	}

	if (valid)
		printf("Yes\n%lld\n", f);
	else
		printf("No\n%lld\n", l);

    return 0;
}
