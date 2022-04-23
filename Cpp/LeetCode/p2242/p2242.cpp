#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int N = scores.size();

        vector<vector<pair<int, int>>> G(N);

        for (vector<int> e: edges) {
            G[e[0]].push_back({e[1], G[e[1]].size()});
            G[e[1]].push_back({e[0], G[e[0]].size() - 1});
        }
    }
};

int main() {

    /* vector<int> scores {9,20,6,4,11,12}; */
    /* vector<vector<int>> edges {{0,3},{5,3},{2,4},{1,3}}; */
    vector<int> scores {5,2,9,8,4};
    vector<vector<int>> edges {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};

    Solution solution;
    cout << solution.maximumScore(scores, edges) << endl;

    return 0;
}
