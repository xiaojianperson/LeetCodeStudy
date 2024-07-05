#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        vector<int> check(nums.size(), -1);
        vector<int> pre(nums.size(), 1);

        int location = -1;
        for (int i = 0;i < nums.size();i++) {
            if (location != -1) {
                if (nums[i] == 0) {
                    location = -1;
                }
                else {
                    check[i] = check[i - 1];
                }


            }
            else if (nums[i] < 0) {
                check[i] = i;
                location = 0;
            }
        }

        pre[0] = nums[0];
        ans = max(pre[0], ans);

        for (int i = 1;i < nums.size();i++) {
            pre[i] = nums[i] * pre[i - 1];
            if (pre[i] == 0) {
                pre[i] = nums[i];
            }

            if (pre[i] < 0 && check[i] != i) {
                ans = max(ans, pre[i] / pre[check[i]]);
            }
            else {
                ans = max(ans, pre[i]);
            }

        }
        return ans;
    }
};

int main() {
    Solution s = Solution();
    vector<int> arr = { -2,0,-1 };
    s.maxProduct(arr);
    return 0;
}