#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int ans = 0;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left == right) {
            return;
        }

        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);


        for (int i = left, j = mid + 1;i <= mid;i++) {
            while (j <= right && nums[i] - 0ll - nums[j] > nums[j]) {
                j++;
            }

            ans += (j - mid - 1);
        }

        vector<int> res;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                res.push_back(nums[i]);
                i++;
            }
            else {
                res.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            res.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            res.push_back(nums[j]);
            j++;
        }

        for (int i = left;i <= right;i++) {
            nums[i] = res[i - left];
        }
    }



    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 2,4,3,5,1 };
    solution.reversePairs(arr);
    return 0;
}