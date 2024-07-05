#include <vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        function(candidates, target, res, 0);
        return ans;
    }

    void function(vector<int>& candidates, int target, vector<int>& res, int count) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }

        for (int i = count;i < candidates.size();i++) {
            if (target >= candidates[i]) {
                res.push_back(candidates[i]);
                function(candidates, target - candidates[i], res, i);
                res.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> candidates = { 2, 3, 6, 7 }; // 示例输入
    int target = 7; // 示例目标和
    std::vector<std::vector<int>> combinations = solution.combinationSum(candidates, target);

    // 输出组合总和结果
    for (const auto& combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
