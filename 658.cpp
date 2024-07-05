#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (x < arr[0]) {
            vector<int> ans(arr.begin(), arr.begin() + k);
            return ans;
        }
        else if (x > arr[arr.size() - 1]) {
            vector<int> ans(arr.end() - k , arr.end() );
            return ans;
        }

        int i = 0;
        while (i < arr.size() && arr[i] <= x) {
            i++;
        }

        vector<int> ans(arr.begin() + max(i - 1 - k + 1, 0), arr.begin() + i);

        for (int j = i;j < arr.size();j++) {
            if (ans.size() < k) {
                ans.emplace_back(arr[j]);
            }
            else {
                if (abs(ans[0] - x) > (arr[j] - x)) {
                    ans.erase(ans.begin());
                    ans.emplace_back(arr[j]);
                }
            }
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 3,5,8,10 };
    vector<int> ans = solution.findClosestElements(arr, 2, 15);
    return 0;
}