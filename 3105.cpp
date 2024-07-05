#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxCount = 1;
        int minCount = 1;
        int ans = 1;

        for (int i = 1;i < nums.size();i++) {
            if (nums[i] > nums[i - 1]) {
                ++maxCount;
                minCount = 1;

            }

            if (nums[i] < nums[i - 1]) {
                ++minCount;
                maxCount = 1;
            }

            if (nums[i] == nums[i - 1]) {
                minCount = 1;
                maxCount = 1;
            }

            ans=max(ans,max(minCount, maxCount));
        }

        return ans;
    }
};

int main() {
    Solution s;
    // s.kidsWithCandies("ABABABAB", "ABAB");
    // s.reverseVowels("leetcode");
    return 0;
}