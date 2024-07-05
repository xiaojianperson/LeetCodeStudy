#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> ans{ 1,2,3,4,5 };
        if (n <= 5) {
            return ans[n - 1];
        }

        unordered_map<long, int> hm;
        for (int i = 0;i < ans.size();i++) {
            ++hm[ans[i]];
        }

        priority_queue<long, vector<long>, greater<long>> pq;
        vector<int> nums{ 2,3,5 };
        int i = 1, j = 0, k = 0;

        while (ans.size() < n + 1) {
            long res = ans[i] * nums[j];

            if (hm[res] == 0) {
                pq.emplace(res);
                ++hm[res];
            }

            ++j;
            if (j == 3) {
                ++i;
                j = 0;

                if (i == ans.size() - 1) {
                    ans.emplace_back(pq.top());
                    pq.pop();
                }
            }
        }

        return ans[n - 1];
    }
};

int main() {
    Solution s;
    s.nthUglyNumber(7);
    return 0;
}