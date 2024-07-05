#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*
1.对tasks,workers排序;
2.从tasks[0]开始遍历;
3.从workers[0]开始,找到tasks[i] <= workers[j] + strength * (pills > 0)对应的j;
或者j==workers.size(),则没有符合条件的元素,++i;
*/
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int ans = 0;

        for (int i = tasks.size() - 1;i >= 0;i--) {
            int j = 0;
            while (j != workers.size() && (workers[j] == -1 || tasks[i] > workers[j] + strength * (pills > 0))) {
                ++j;
            }

            if (j != workers.size() && tasks[i] <= workers[j] + strength * (pills > 0)) {
                ++ans;

                if (tasks[i] > workers[j]) {
                    --pills;
                }

                tasks[i] = -1;
                workers[j] = -1;
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