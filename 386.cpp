#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void check(int cur, int n, vector<int>& ans) {
        for (int i = 0;i <= 9;i++) {
            if (cur * 10 + i <= n) {
                ans.push_back(cur * 10 + i);
                check(cur * 10 + i, n, ans);
            }
            else {
                break;
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for (int i = 0;i < min(9, n);i++) {
            ans.push_back(i + 1);
            check(i + 1, n, ans);
        }

        return ans;
    }
};


int main() {
    // 本地测试代码
    Solution solution;
    return 0;
}