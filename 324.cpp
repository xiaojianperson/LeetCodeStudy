#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp = nums;
        for (int i = 0;i < (nums.size() + 1) / 2;i++) {
            nums[2 * i] = tmp[(nums.size() + 1) / 2 - 1 - i];
        }
        for (int i = 0;i < nums.size() / 2;i++) {
            nums[2 * i + 1] = tmp[nums.size() - i - 1];
        }
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 4,5,5,6 };
    solution.wiggleSort(arr);
    return 0;
}