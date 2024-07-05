#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //双指针初始化指向数组末尾
        int left = nums.size() - 1, right = nums.size() - 1;

        //left - 1指向第一个递减值或指向0
        while (left > 0 && nums[left - 1] >= nums[left]) {
            --left;
        }

        //left指向第一个递减值或等于-1
        --left;

        //找到nums[right]>nums[left]对应的right值,并交换
        if (left != -1) {
            while (nums[right] <= nums[left]) {
                --right;
            }
            swap(nums[left], nums[right]);
        }

        //翻转后续元素
        reverse(nums.begin() + left + 1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> arr = { 1,1,5 };
    s.nextPermutation(arr);
    return 0;
}

