#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    bool Count(int x) {
        double n = sqrt(x);

        if (n != (int)n) {
            return false;
        }
        else {
            for (int i = 2;i < n;i++) {
                if (x % i == 0) {
                    return false;
                }
            }
        }

        return true;;
    }

    int nonSpecialCount(int l, int r) {
        int res = 0;
        for (int i = max(l, 4);i <= r;i++) {
            res += Count(i);
        }

        return r - l + 1 - res;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    cout << solution.nonSpecialCount(4, 16);
    return 0;
}