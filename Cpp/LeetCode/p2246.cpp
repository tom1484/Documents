#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

class Solution {
public:
    vector<vector<int>> child;
    string str;
    int ans = 1;

    int dfs(int x) {
        int p1 = 0, p2 = 0;

        for (int j : child[x]) {
            if (str[x] == str[j]) {
                dfs(j);
                continue;
            }

            p2 = max(p2, dfs(j));
            if (p2 > p1)
                swap(p1, p2);
        }

        ans = max(ans, p1 + p2 + 1);

        /* cout << x << ": " << p1 << ", " << p2 << endl; */

        return p1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int N = parent.size();

        child.resize(N);
        for (int i = 1; i < N; i ++)
            child[parent[i]].push_back(i);

        str = s;

        dfs(0);
        
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    /* vector<int> parent{-1, 0, 0, 1, 1, 2}; */
    /* string s = "abacbe"; */
    vector<int> parent{-1, 0, 1};
    string s = "aab";

    cout << solution.longestPath(parent, s) << endl;

    return 0;
}
