#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool ans = true;

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> um;
        for (int i = 0;i < graph.size();i++) {
            if (um[i] == 0) {
                um[i] = 1;
                check(um, graph, i);
            }
        }

        return ans;
    }

    void check(unordered_map<int, int>& um, const vector<vector<int>>& graph, int index) {
        for (int i = 0;i < graph[index].size();i++) {
            if (um[graph[index][i]] == 0) {
                um[graph[index][i]] = um[index] * -1;
                check(um, graph, graph[index][i]);
            }
            else {
                if (um[index] == um[graph[index][i]]) {
                    ans = false;
                }
            }
        }
    }
};

int main() {
    // 本地测试代码
    Solution solution;

    vector<vector<int>> arr = { {2,3,4},{1,4,5},{1,5,6},{1,2},{2,3,6},{{3,5}} };
    solution.isBipartite(arr);
    return 0;
}