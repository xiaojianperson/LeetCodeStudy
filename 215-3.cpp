#include<iostream>
#include<vector>
using namespace std;

/*
    采用快速排序算法，随机选择一个元素pivot，将nums分成value<pivot，value=pivot，value>pivot三组；
    再对两边的元素递归，当第k个元素位于value=pivot的部分时，返回pivot的值
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

    int quickSelect(vector<int>& nums, int k) {
        if (nums.empty()) return -1; // 边界条件检查
        int pivot = nums[rand() % nums.size()];
        vector<int> small, mid, large;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                small.push_back(nums[i]);
            }
            else if (nums[i] == pivot) {
                mid.push_back(nums[i]);
            }
            else {
                large.push_back(nums[i]);
            }
        }
        if (large.size() >= k) {
            return quickSelect(large, k);
        }
        else if (large.size() + mid.size() < k) {
            return quickSelect(small, k - (large.size() + mid.size()));
        }
        else {
            return pivot;
        }
    }
};

int main() {
    Solution s;
    vector<int> arr = { 3,2,1,5,6,4 };
    s.findKthLargest(arr, 2);
}