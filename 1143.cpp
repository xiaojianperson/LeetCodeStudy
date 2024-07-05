#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.size() + 1);
        dp[0] = 0;
        int begin = 0;
        int ans = 0;
        for (int i = 1;i < text1.size() + 1;i++) {
            dp[i] = dp[i - 1];
            for (int j = begin;j < text2.size() + begin;j++) {
                if (text1[i - 1] == text2[j % text2.size()]) {
                    dp[i] = dp[i - 1] + 1;
                    if (j % text2.size() + 1 <= begin) {
                        ans = max(ans, dp[i] - 1);
                        dp[i] = 1;
                        begin = j % text2.size() + 1;
                    }
                    else {
                        begin = j % text2.size() + 1;
                    }
                    break;;
                }
            }
        }
        return ans == 0 ? dp[text1.size()] : ans;
    }
};

int main() {
    Solution s;
    s.longestCommonSubsequence("ghbrgc", "hafcdqbgncrcbihkd");
    return 0;
}