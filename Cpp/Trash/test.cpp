#include <bits/stdc++.h>
using namespace std;


const int N = 50;
const int T = 5000000;


int main() {

    srand(time(0));

    double th = 1;
    double cnt = 0;

    for (int i = 0; i < N; i ++)
        th /= 2.71828182845905;

    for (int i = 0; i < T; i ++) {
        double r = 1;
        for (int j = 0; j < N; j ++) {
            r *= (double) rand() / RAND_MAX;
        }
        if (r <= th)
            cnt += 1.0 / T;
    }

    cout << cnt;


    return 0;
}
