#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n > 0) {
            return x * myPow(x, n - 1);
        }
        else if (n < 0) {
            return (1 / x) * myPow(x, n + 1);
        }

        return 1.0;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    cout << solution.myPow(10.0, 7);
    return 0;
}