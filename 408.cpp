#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include <iomanip>
using namespace std;

class Solution {
public:
    //构建两个优先队列，small，big
    //当k为偶数时,small大小等于big,中位数为两个队列队首之和除以2
    //当k为奇数时,中位数为small队首元素.small队列长度减去big队列长度等于1
    //1.将窗口内元素添加到small中
    //2.对small进行出队操作,直至small.size()-big.size()<=1
    //3.取中位数
    //4.将新元素加入队列中
    //5.

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        if (k == 1) {
            for (int i = 0;i < nums.size();i++) {
                ans.emplace_back(nums[i]);
            }
            return ans;
        }

        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>>big;

        for (int i = 0;i < k;i++) {
            small.emplace(nums[i]);
        }

        while (small.size() - big.size() != k % 2) {
            big.emplace(small.top());
            small.pop();
        }

        ans.emplace_back(((long long)small.top() + ((long long)big.top() * (1 - k % 2))) / (1 + (1 - k % 2)));

        int blance = 0;

        unordered_map<int, int> deleteCount;

        for (int i = k;i < nums.size();i++) {
            int left = nums[i - k];
            int right = nums[i];

            ++deleteCount[left];

            if (left <= small.top()) {
                --blance;
            }
            else {
                ++blance;
            }

            if (right <= small.top()) {
                small.emplace(right);
                ++blance;
            }
            else {
                big.emplace(right);
                --blance;
            }

            if (blance == 2) {
                big.emplace(small.top());
                small.pop();
                blance = 0;
            }
            else if (blance == -2) {
                small.emplace(big.top());
                big.pop();
                blance = 0;
            }

            while (deleteCount[small.top()] != 0) {
                --deleteCount[small.top()];
                small.pop();
            }

            while (deleteCount[big.top()] != 0) {
                --deleteCount[big.top()];
                big.pop();
            }
            ans.emplace_back(((long long)small.top() + ((long long)big.top() * (1 - k % 2))) / (1 + (1 - k % 2)));
        }
        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 2147483647,2147483647 };
    solution.medianSlidingWindow(arr, 2);
    return 0;
}
