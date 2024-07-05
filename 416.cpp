#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm> 
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int res = sum / 2;
        vector<int> dp(res + 1);

        dp[0] = 1;

        for (int j = 0;j < nums.size();j++) {
            for (int i = res;i >= nums[j];i--) {
                // dp[i + nums[j]] = dp[i] || dp[i + nums[j]];
                dp[i] = dp[i] || dp[i - nums[j]];
            }
        }
        
        return dp[res];
    }
};