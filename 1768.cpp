#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int count = 0;
        string ans;
        while (count < word1.size() || count < word2.size()) {
            if (count < word1.size()) {
                ans += word1[count];
            }
            if (count < word2.size()) {
                ans += word2[count];
            }
            count++;
        }
        return ans;
    }
};