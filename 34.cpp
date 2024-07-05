#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty() || target > nums[nums.size() - 1] || target < nums[0]) {
            return ans;
        }

        // int left = 0;
        // int right = nums.size() - 1;

        function(nums, target, 0, nums.size() - 1, ans);
        return ans;
    }

    void function(vector<int>& nums, int target, int left, int right, vector<int>& ans) {
        if (left > right) {
            return;
        }

        int loc = (left + right) / 2;
        int res = nums[loc];

        if (res > target) {
            function(nums, target, left, loc - 1, ans);
        }

        if (res < target) {
            function(nums, target, loc + 1, right, ans);
        }

        if (res == target) {
            if (loc == 0 || nums[loc - 1] < target) {
                ans[0] = loc;
            }
            else {
                function(nums, target, left, loc - 1, ans);
            }

            if (loc == nums.size() - 1 || nums[loc + 1] > target) {
                ans[1] = loc;
            }
            else {
                function(nums, target, loc + 1, right, ans);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    cout << "The target " << target << " is in the range: ["
        << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}