#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;

        while (slow != nums.size()) {
            while (fast != nums.size() && nums[fast] == nums[slow]) {
                ++fast;
            }

            if (fast > slow + 1)
                nums.erase(nums.begin() + slow, nums.begin() + fast - 1);

            fast = ++slow;
        }

        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> arr = { 1,1 };
    s.removeDuplicates(arr);
    return 0;
}