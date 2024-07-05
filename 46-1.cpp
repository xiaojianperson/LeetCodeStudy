#include <vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> check(nums.size(), 1);
        vector<int> res;
        function(nums, check, res);
        return ans; // 返回全排列结果
    }

    void function(const vector<int>& nums, vector<int>& check, vector<int>& res) {
        bool end = true;

        for (int i = 0; i < check.size(); ++i) {
            if (check[i]) {
                check[i] = 0;
                res.push_back(nums[i]);
                function(nums, check, res);
                end = false;
                res.pop_back(); // 回溯，恢复状态
                check[i] = 1;
            }
        }

        if (end)
            ans.push_back(res);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> permutations = solution.permute(nums);

    // 输出全排列结果
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
