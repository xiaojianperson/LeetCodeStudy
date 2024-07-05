#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto compare = [](vector<int>& a, vector<int>& b) {
            return a[0] <= b[0];
            };
        priority_queue <vector<int>, vector<vector<int>>, decltype(compare) > pq(compare);

        for (int i = 0;i < prices.size();i++) {
            pq.emplace(vector<int>{ prices[i], i });
        }

        int count = (prices.size() + 1) / 2;

        vector<int> check(prices.size(), 0);

        while (count != 0 && count--) {
            check[pq.top()[1]] = -1;
            pq.pop();
        }

        int res = 0;

        int buyNum = prices[0];

        for (int i = 0;i < prices.size();i++) {
            buyNum = min(prices[i], buyNum);
            if (check[i] == -1) {
                res += prices[i] - buyNum;
                if (i != prices.size() - 1) {
                    buyNum = prices[i + 1];
                }
            }
        }

        return res;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = {1,2,3,4,5};
    solution.maxProfit(arr);
    return 0;
}