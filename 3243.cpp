#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int length = queries.size();
        vector<vector<int>> map;
        vector<int> res(n);

        for (int i = 0;i < n;i++) {
            map.emplace_back(vector<int>{i + 1});
            res[i] = i;
        }

        vector<int> ans(length);

        for (int i = 0;i < queries.size();i++) {
            map[queries[i][0]].emplace_back(queries[i][1]);

            for (int j = queries[i][0];j < n - 1;j++) {
                for (int k = 0;k < map[j].size();k++) {
                    int a = res[j], b = res[map[j][k]];
                    res[map[j][k]] = min(res[j] + 1, res[map[j][k]]);
                }
            }

            ans[i] = res[n - 1];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> queries = { {2, 4}, {0, 2}, {0, 4} };
    int n = 5; // 假设数组长度为7
    vector<int> result = solution.shortestDistanceAfterQueries(n, queries);

    // 打印结果
    cout << "Shortest distances after queries: ";
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}