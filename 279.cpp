#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0;i <= n;i++) {
            dp[i] = i;
        }
        for (int i = 2;i <= n;i++) {
            for (int j = sqrt(i);j > 0;j--) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s = Solution();
    cout << s.numSquares(43);
    return 0;
}