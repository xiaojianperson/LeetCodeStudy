#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int length = queries.size();
        vector<int> ans(0);
        set<int> st;

        for (int i = 0;i < n;i++) {
            st.insert(i);
        }

        for (int i = 0;i < length;i++) {
            int first = queries[i][0], second = queries[i][1];
            // for (int j = first + 1;j < second;j++) {
            //     st.insert(j);
            // }
            st.erase(st.upper_bound(first), st.lower_bound(second));

            ans.push_back(st.size() - 1);
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