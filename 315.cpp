#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> res;
    // 注意这里直接传存pair的vector，对其first进行归并排序，通过其second保有原数组下标
    void merge_sort(vector<pair<int, int>> &vec, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) >> 1;
        merge_sort(vec, l, mid);
        merge_sort(vec, mid + 1, r);
        int i = l, j = mid + 1;
        vector<pair<int, int>> tmp;
        while (i <= mid && j <= r) {
            if (vec[i].first <= vec[j].first) {
                res[vec[i].second] += j - mid - 1; // 区间[mid + 1, j - 1]
                tmp.push_back(vec[i++]); // 对应于原本归并排序的tmp[k++] = vec[i++];
            } else {
                tmp.push_back(vec[j++]);
            }
        }
        while (i <= mid) {
            res[vec[i].second] += j - mid - 1; // 区间[mid + 1, r]。注意这里本应是r-mid，但为了方便记忆和上面保持一致，因为j=r+1
            tmp.push_back(vec[i++]);
        }
        while (j <= r) {
            tmp.push_back(vec[j++]);
        }
        for (int i = l, j = 0; i <= r && j < tmp.size(); i++, j++) {
            vec[i] = tmp[j];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<pair<int, int>> nums_pair;
        for (int i = 0; i < nums.size(); i++) {
            nums_pair.push_back({nums[i], i});
        }
        res = vector<int>(nums.size(), 0);
        merge_sort(nums_pair, 0, nums_pair.size() - 1);
        return res;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> nums = { 251,9,21,84,66,65,36,100,41 };
    solution.countSmaller(nums);
    return 0;
}