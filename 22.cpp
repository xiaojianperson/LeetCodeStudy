#include <vector>
#include <string>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res = "(";
        int count = 0;
        int depth = 2 * (n - 1);

        funciton(ans, count, res, depth);

        return ans;
    }

    void funciton(vector<string>& ans, int& count, string& res, int& depth) {
        if (depth == 0 || count < -1) {
            if (count == 0) {
                res.push_back(')');
                ans.push_back(res);
                res.pop_back();
            }
            return;
        }

        for (int i = 0;i < 2;i++) {
            --depth;
            count += (1 - 2 * i);
            res.push_back('(' + i);

            funciton(ans, count, res, depth);

            res.pop_back();
            ++depth;
            count -= (1 - 2 * i);
        }
    }
};

int main() {
    Solution solution;
    int n = 3; // 示例输入
    std::vector<std::string> combinations = solution.generateParenthesis(n);

    // 输出生成的括号组合
    for (const std::string& combination : combinations) {
        std::cout << combination << std::endl;
    }

    return 0;
}
