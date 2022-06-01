#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> ones;
vector<int> zeros;

void count(int n) {
    
    int o = 0, z = 0;

    if (n == 0) {
        z ++;
    }

    while (n > 0) {
        if (n % 2 == 1)
            o ++;
        else
            z ++;

        n /= 2;
    }

    ones.push_back(o);
    zeros.push_back(z);
}

int main() {

    fstream Input;
    Input.open("Q5_test1_B.txt");

    for (int i = 0; i < 8; i ++)
        Input.get();

    int n;
    while (true) {
        Input >> n;

        count(n);

        if (Input.get() == '\n')
            break;
        Input.get();
    }

    int x, y;

    for (int i = 0; i < 4; i ++)
        Input.get();

    Input >> x;
    Input.get();

    for (int i = 0; i < 4; i ++)
        Input.get();

    Input >> y;
    Input.get();

    int N = ones.size();
    int N_sub = 1;

    int ans = N;

    for (int i = 0; i < N; i ++)
        N_sub *= 2;
 
    for (int s = 1; s < N_sub; s ++) {
        int p = s;
        int cnt = 0;
        int o = 0, z = 0;
        
        for (int j = 0; j < N; j ++, p /= 2) {
            if (p % 2 == 1) {
                o += ones[j];
                z += zeros[j];
                cnt ++;
            }
        }

        /* cout << o << ' ' << z << endl; */
        if (x <= z and y <= o)
            ans = min(ans, cnt);
    }

    cout << ans << endl;


    return 0;
}
