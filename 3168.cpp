#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        if (s == "") {
            return 0;
        }

        int count = 0;
        int res = 0;

        for (int i = 0;i < s.size();i++) {
            if (s[i] == 'E') {
                ++count;
                res = max(count, res);
            }
            else {
                --count;
            }
        }
        return res;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    return 0;
}