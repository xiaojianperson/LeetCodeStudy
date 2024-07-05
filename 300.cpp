#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> check(nums.size(), 1);
        vector<int> dp(nums.size(), 1);
        int length = 1;
        for (int i = 1;i < nums.size();i++) {
            for (int j = 0;j < i;j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    length = max(length, dp[i]);
                }
            }
        }

        return length;
    }
};