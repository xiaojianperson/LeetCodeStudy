#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //    for (int i = nums.size() / 2; i >= 0; --i) {
    //         function1(nums, i);
    //    }
    function1(nums, 0);
        
        swap(nums[0], nums[nums.size() - 1]);
        for (int i = 1;i < k;i++) {
            function(nums, 0, i);
            swap(nums[0], nums[nums.size() - 1 - i]);
        }
        return nums[nums.size() - k];
    }

    void function(vector<int>& nums, int node, int count) {
        int l = 2 * node + 1;
        int r = l + 1;

        int maxChild = node;
        if (l  < nums.size() - count && nums[l] > nums[node]) {
            maxChild = l;
        }

        if (r  < nums.size() - count && nums[r] > nums[maxChild]) {
            maxChild = r;
        }

        // 如果存在更大的子节点，交换它们的位置
        if (maxChild != node) {
            swap(nums[maxChild], nums[node]);
            function(nums, maxChild, count);
        }
    }

    void function1(vector<int>& nums, int node) {
        int l = 2 * node + 1;
        int r = l + 1;


        if (l < nums.size()) {
            function1(nums, l);
        }

        if (r < nums.size()) {
            function1(nums, r);
        }

        int maxChild = node;
        if (l  < nums.size() && nums[l] > nums[node]) {
            maxChild = l;
        }

        if (r  < nums.size() && nums[r] > nums[maxChild]) {
            maxChild = r;
        }

        // 如果存在更大的子节点，交换它们的位置
        if (maxChild != node) {
            swap(nums[maxChild], nums[node]);
            function1(nums, maxChild);
        }
    }
};

int main() {
    vector<int> arr = { 3,2,3,1,2,4,5,5,6 };
    Solution s = Solution();
    cout << s.findKthLargest(arr, arr.size());
    return 0;
}