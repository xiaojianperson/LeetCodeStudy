#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1;i < dp.size();i++) {
            for (int j = 0;j < coins.size();j++) {
                if (i - coins[j] >= 0) {
                    if (dp[i - coins[j]] != -1) {
                        dp[i] = dp[i] == -1 ? dp[i - coins[j]] + 1 : min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution s = Solution();
    vector<int> arr = { 2 };
    cout << s.coinChange(arr, 3);
    return 0;
}