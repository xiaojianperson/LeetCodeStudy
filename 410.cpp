#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<long long> subNums(nums.size(), nums[0]);
        for (int i = 1;i < nums.size();i++) {
            subNums[i] = subNums[i - 1] + nums[i];
        }

        vector<vector<long long>>dp(nums.size(), vector<long long>(k+1, LONG_MAX));

        for (int i = 0;i < nums.size();i++) {
            dp[i][1] = subNums[i];
        }

        for (int i = 0;i < nums.size();i++) {
            for (int j = 0;j <= i - 1;j++) {
                for (int m = 2;m <= min(k, i + 1);m++) {
                    dp[i][m] = min(dp[i][m],max(dp[j][m - 1], subNums[i] - subNums[j]));
                }
            }
        }

        return dp[nums.size() - 1][k];
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 7,2,5,10,8 };
    solution.splitArray(arr, 2);
    return 0;
}