#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int check(vector<int>& nums, int index) {
        bool res = true;

        if (index > 0) {
            int leftValue = nums[index - 1];
            if (leftValue >= nums[index] && res) {
                res = false;
            }
        }

        if (index < nums.size() - 1) {
            int rightValue = nums[index + 1];
            if (rightValue >= nums[index] && res) {
                res = false;
            }
        }

        return res;

    }

    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (check(nums, mid)) {
                return mid;
            }
            else if (mid < nums.size() - 1 && nums[mid + 1] >= nums[mid]) {
                left++;
            }
            else if (mid > 0 && nums[mid - 1] >= nums[mid]) {
                right--;
            }
        }

        return -1;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 1,2 };
    solution.findPeakElement(arr);
    return 0;
}