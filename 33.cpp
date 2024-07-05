#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ans = -1;
    int search(vector<int>& nums, int target) {


        if (nums.empty()) {
            return ans;
        }

        function(nums, 0, nums.size() - 1, target);

        return ans;
    }

    void function(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return;
        }
        int mid = (left + right) / 2;
        int midValue = nums[mid];

        if (midValue == target) {
            ans = mid;
            return;
        }

        if (midValue < target) {
            if (target < nums[0]) {
                function(nums, mid + 1, right, target);
            }
            else {
                if (midValue < nums[0]) {
                    function(nums, left, mid - 1, target);
                }
                else {
                    function(nums, mid + 1, right, target);
                }
            }
        }
        else {//midValue > target
            if (target > nums[nums.size() - 1]) {
                function(nums, left, mid - 1, target);
            }
            else {
                if (midValue > nums[nums.size() - 1]) {
                    function(nums, mid + 1, right, target);
                }
                else {
                    function(nums, left, mid - 1, target);
                }
            }
        }

    }
};