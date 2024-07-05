#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int p = pills;
        deque<int> ws;
        int ptr = workers.size() - 1;
        // 从大到小枚举每一个任务
        for (int i = mid - 1; i >= 0; --i) {
            while (ptr >= workers.size() - mid && workers[ptr] + strength >= tasks[i]) {
                ws.push_front(workers[ptr]);
                --ptr;
                cout <<endl ;
            }
            if (ws.empty()) {
                return false;
            }
            // 如果双端队列中最大的元素大于等于 tasks[i]
            else if (ws.back() >= tasks[i]) {
                ws.pop_back();
            }
            else {
                if (!p) {
                    return false;
                }
                --p;
                ws.pop_front();
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 1, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr1 = { 5,9,8,5,9 };
    vector<int> arr2 = { 1,6,4,2,6 };
    Solution s;
    s.maxTaskAssign(arr1, arr2, 1, 5);
    return 0;
}