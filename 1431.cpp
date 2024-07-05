#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxValue = 0;
        for (auto i : candies) {
            maxValue = max(maxValue, i);
        }
        vector<bool> ans(candies.size(), false);
        for (int i = 0;i < candies.size();i++) {
            if (candies[i] + extraCandies >= maxValue) {
                ans[i] = true;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    // s.kidsWithCandies("ABABABAB", "ABAB");
    return 0;
}