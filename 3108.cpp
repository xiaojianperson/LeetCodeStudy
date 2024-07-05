#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> tu(n);
        vector<int> check(n, -1);
        int count = 0;
        for (int i = 0;i < edges.size();i++) {
            if (check[edges[i][0]] == -1) {
                tu[count].push_back(edges[i][0]);
                check[edges[i][0]] = count;
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}