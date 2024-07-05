#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> check;
        string s1 = "aeiouAEIOU";

        for (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s1.size();j++) {
                if (s[i] == s1[j]) {
                    check.push_back(s[i]);
                    break;
                }
            }
        }

        int count = 1;

        for (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s1.size();j++) {
                if (s[i] == s1[j]) {
                    s[i] = check[check.size() - count];
                    ++count;
                    break;
                }
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    // s.kidsWithCandies("ABABABAB", "ABAB");
    s.reverseVowels("leetcode");
    return 0;
}