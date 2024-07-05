#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long count = 0;
        int target = nums.size() / 2;

        sort(nums.begin(), nums.end());
        count += max(k - nums[target], nums[target] - k);

        nums[target] = k;
        
        for (int i = 0;i < nums.size();i++) {
            if (i<target && nums[i]>k) {
                count += nums[i] - k;
            }
            if (i > target && nums[i] < k) {
                count += k - nums[i];
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> arr = { 1,1,1 };
    s.minOperationsToMakeMedianK(arr, 1000000000);
    return 0;
}