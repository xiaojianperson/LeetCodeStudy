#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.size() + 1);
        int length = 0;
        int ans = 0;

        dp[0] = 0;

        for (int i = 1;i < s.size() + 1;i++) {
            int check = 1 - 2 * (s[i - 1] - '(');
            dp[i] = max(check, dp[i - 1] + check);

            if (check == -1) {
                length += 2;
            }

            if (dp[i] < 0) {
                dp[i] = 0;
                length = 0;
            }

            if (dp[i] >= 0 && check == -1) {
                ans = max(ans, length);
            }
        }

        return ans;
    }
};


int main() {
    Solution s = Solution();
    s.longestValidParentheses("()(()");
    return 0;
}