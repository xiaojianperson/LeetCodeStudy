#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int func(int x) {
        if (x == 0) {
            return 1;
        }

        return x * func(x - 1);
    }

    int getNum(vector<int>& check, int x) {
        int count = 0;
        int res1 = 0;

        for (int i = 0;i < check.size();i++) {
            if (check[i] == 0) {
                continue;
            }

            ++count;

            if (count == x) {
                check[i] = 0;
                res1 = i + 1;
                break;
            }
        }

        return res1;
    }

    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        vector<int> check(n, 1);
        vector<int> res(n, 0);
        string ans;

        for (int i = 0;i < n - 2;i++) {
            if (k % func(n - i - 1) == 0) {
                res[i] = k / func(n - i - 1);
            }
            else {
                res[i] = k / func(n - i - 1) + 1;
            }

            k -= (res[i] - 1) * func(n - i - 1);
        }

        if (k == 1) {
            res[n - 2] = 1;
            res[n - 1] = 1;
        }
        else {
            res[n - 2] = 2;
            res[n - 1] = 1;
        }

        for (int i = 0;i < res.size();i++) {
            ans += (getNum(check, res[i]) + '0');
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    solution.getPermutation(3, 2);
    return 0;
}