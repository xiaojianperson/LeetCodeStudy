#include <vector>
#include <algorithm>
#include<vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> check(nums.size(), 1);
        vector<int> res;
        funciton(nums, check, res);
    }

    void funciton(vector<int> nums, vector<int>& check, vector<int> res) {
        bool end = true;

        for (auto i : check) {
            if (i) {
                i = 0;
                res.push_back(nums[i]);
                funciton(nums, check, res);
                end = false;
                i = 1;
            }
        }

        if (end)
            ans.push_back(res);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 2, 3 };
    std::vector<std::vector<int>> permutations = solution.permute(nums);

    // 输出全排列结果
    for (const auto& perm : permutations) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
