#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string s1;
        vector<int> check(s.size() + 1, 0);
        check[0] = 1;
        for (int i = 0;i < s.size();i++) {
            for (int j = i;j >= 0;j--) {
                if (check[j] == 1) {
                    s1 = s.substr(j, i - j + 1);
                    for (int k = 0;k < wordDict.size();k++) {
                        if (s1 == wordDict[k]) {
                            check[i+1] = 1;
                        }
                    }
                }

            }
        }
        return check[s.size()];
    }
};

int main() {
    vector<string> res = { "leet", "code" };
    Solution s = Solution();
    s.wordBreak("leetcode", res);
    return 0;
}