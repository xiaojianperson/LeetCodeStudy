#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for (auto ch : s) {
            if (ch == '}' || ch == ']' || ch == ')') {
                if (check.empty()) {
                    return false;
                }
                if (ch == '}' && check.top() == '{') {
                    check.pop();
                    continue;
                }
                else if (ch == ']' && check.top() == '[') {
                    check.pop();
                    continue;
                }
                else if (ch == ')' && check.top() == '(') {
                    check.pop();
                    continue;
                }
                return false;
            }
            else {
                check.push(ch);
            }
        }

        return check.empty();
    }
};

int main() {
    Solution s;
    s.isValid("()");
    return 0;
}