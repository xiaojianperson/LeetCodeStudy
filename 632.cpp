#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2, 0);

        int left = INT_MAX, right = INT_MIN;

        auto comp = [](vector<int>& arr1, vector<int>& arr2) {
            return arr1[0] > arr2[0];
            };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (int i = 0;i < nums.size();i++) {
            right = max(nums[i][0], right);
            pq.emplace(vector<int>{ nums[i][0], i, 0});
        }

        ans = { pq.top()[0],right };

        int count = 1;

        while (count != 0) {
            vector<int> cur = pq.top();
            pq.pop();

            if (cur[2] != nums[cur[1]].size() - 1) {
                int value = nums[cur[1]][cur[2] + 1];
                right = max(value, right);

                pq.emplace(vector<int>{value, cur[1], cur[2] + 1});
            }
            else {
                --count;
                left = min(left, cur[0]);

            }

            if (count == 0) {
                if (right - left < ans[1] - ans[0]) {
                    ans = { left,right };
                }

            }
            else if (right - pq.top()[0] < ans[1] - ans[0]) {
                ans = { pq.top()[0],right };
            }
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    // vector<vector<int>> arr = {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}, {-8, 8}, {-9, 9}, {-10, 10}, {-11, 11}, {-12, 12}, {-13, 13}, {-14, 14}, {-15, 15}, {-16, 16}, {-17, 17}, {-18, 18}, {-19, 19}, {-20, 20}, {-21, 21}, {-22, 22}, {-23, 23}, {-24, 24}, {-25, 25}, {-26, 26}, {-27, 27}, {-28, 28}, {-29, 29}, {-30, 30}, {-31, 31}, {-32, 32}, {-33, 33}, {-34, 34}, {-35, 35}, {-36, 36}, {-37, 37}, {-38, 38}, {-39, 39}, {-40, 40}, {-41, 41}, {-42, 42}, {-43, 43}, {-44, 44}, {-45, 45}, {-46, 46}, {-47, 47}, {-48, 48}, {-49, 49}, {-50, 50}, {-51, 51}, {-52, 52}, {-53, 53}, {-54, 54}, {-55, 55}};
    vector<vector<int>> arr = { {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30} };
    solution.smallestRange(arr);
    return 0;
}