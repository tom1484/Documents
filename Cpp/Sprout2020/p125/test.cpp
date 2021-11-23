#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a-1; i >= b; i--)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

using namespace std;

const ll MOD = 10000019;

ll arr[1000000] = {};
ll tmp[1000000] = {};
ll ans = 0;

ll mod (ll x) {
	return x % MOD;
}

void solve(ll lt, ll rt){
    if (lt + 1 == rt)
        return;

    ll mid = (lt + rt) / 2;
    solve(lt, mid);
    solve(mid, rt);

    ll p = lt, q = mid;
    FOR (i, lt, rt) {
        if (p < mid && (q == rt || arr[p] <= arr[q])){
            ans = mod(ans + arr[p] * (q - mid));
            tmp[i] = arr[p++];
        }
        else {
            ans += arr[q] * (mid - p);
            ans = mod(ans + arr[q] * (mid - p));
            tmp[i] = arr[q++];
        }
    }

    FOR (i, lt, rt)
        arr[i] = tmp[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;

    FOR (i, 0, N)
        cin >> arr[i];

    solve(0, N);
    cout << ans << '\n';

	return 0;
}
/* #include<bits/stdc++.h> */
/* //#define endl '\n' */

/* using namespace std; */

/* int num[1000000] = {}; */
/* int merge_arr[1000000] = {}; */
/* long long sum = 0; */

/* void merge_sort(int, int); */

/* int main(){ */
    /* ios_base::sync_with_stdio(false); */
    /* cin.tie(0); */

    /* int n; */
    /* cin >> n; */

    /* for(int i=0; i<n; i++){ */
        /* cin >> num[i]; */
    /* } */

    /* merge_sort(0, n); */

/* //    for(int i=0; i<n; i++){ */
/* //        cout << num[i] << " "; */
/* //    } */
    /* cout << sum << endl; */
/* } */

/* void merge_sort(int l, int r){ */
    /* if(l + 1 == r) */
        /* return; */

    /* int mid = (l + r) / 2; */
    /* merge_sort(l, mid); */
    /* merge_sort(mid, r); */
    /* int left = l, right = mid; */

    /* for(int i=l; i<r; i++){ */
        /* if(left != mid and (right == r or num[left] <= num[right])){ */
            /* sum += (long long)num[left] * (right - mid); */
            /* sum %= 10000019; */
            /* merge_arr[i] = num[left]; */
            /* left++; */
        /* } */
        /* else{ */
            /* sum += (long long)num[right] * (mid - left); */
            /* sum %= 10000019; */
            /* merge_arr[i] = num[right]; */
            /* right++; */
        /* } */
    /* } */

    /* for(int i=l; i<r; i++){ */
        /* num[i] = merge_arr[i]; */
    /* } */
/* } */
