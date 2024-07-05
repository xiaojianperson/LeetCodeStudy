#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }

        int count = 0;
        int location = 0;
        vector<char> stk;

        stk.push_back(num[0]);

        while (location < num.size() - 1) {
            ++location;

            while (!stk.empty() && num[location] - stk[stk.size() - 1] < 0 && count < k) {
                stk.pop_back();
                ++count;
            }

            if (stk.empty() || num[location] - stk[stk.size() - 1] >= 0 || count == k) {
                stk.push_back(num[location]);
            }
        }

        string ans;
        int length = stk.size();

        for (auto ch : stk) {
            ans += ch;
        }

        ans = ans.substr(0, num.size() - k);

        while (ans[0] == '0') {
            ans = ans.substr(1, ans.size() - 1);
        }



        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution s;
    s.removeKdigits("10001", 4);
}