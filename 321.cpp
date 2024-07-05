#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        vector<int> v1;
        vector<int> v2;

        vector<int> res;
        vector<int> ans(k, 0);

        for (int i = 0;i <= k;i++) {
            v1.clear();
            v2.clear();
            res.clear();

            int count = l1 - i;
            for (int j = 0;j < l1;j++) {
                while (!v1.empty() && nums1[j] > v1[v1.size() - 1] && count) {
                    v1.pop_back();
                    --count;
                }
                if (v1.size() < i) {
                    v1.push_back(nums1[j]);

                }
                else if (v1.size() == i) {
                    --count;
                }
            }

            count = l2 - (k - i);
            for (int j = 0;j < l2;j++) {
                while (!v2.empty() && nums2[j] > v2[v2.size() - 1] && count) {
                    v2.pop_back();
                    --count;
                }
                if (v2.size() < k - i) {
                    v2.push_back(nums2[j]);

                }
                else if (v1.size() == k - i) {
                    --count;
                }
            }

            auto iter1 = v1.begin(), iter2 = v2.begin();
            while (iter1 != v1.end() || iter2 != v2.end()) {
                res.push_back(lexicographical_compare(iter1, v1.end(), iter2, v2.end()) ? *iter2++ : *iter1++);
            }


            // 如果归并后的最大子序列大于目前已找到的最大子序列，则更新解
            ans = lexicographical_compare(ans.begin(), ans.end(), res.begin(), res.end()) ? res : ans;

        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int >arr1 = { 6,7,5 };
    vector<int >arr2 = { 4,8,1 };
    s.maxNumber(arr1, arr2, 3);
    return 0;
}
