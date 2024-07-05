#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

    class Solution {
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> prefixAnd(nums1.size(), vector<int>(nums2.size(), 0));

            int count = prefixAnd[0][0];

            for (int i = 0;i < nums1.size();i++) {
                for (int j = 0;j < nums2.size();j++) {
                    prefixAnd[i][j] = nums1[i] == nums2[j] ? (i == 0 || j == 0 ? 1 : prefixAnd[i - 1][j - 1] + 1) : 0;
                    count = max(prefixAnd[i][j], count);
                }
            }

            return count;
        }
    };

int main() {
    // 本地测试代码

    vector<int> arr1 = { 1,2,3,2,1 };
    vector<int> arr2 = { 3,2,1,4,7 };

    Solution solution;

    solution.findLength(arr1, arr2);
    return 0;
}
