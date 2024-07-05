#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = { 0 };
        int check[26] = { 0 };
        stack<char> stk;

        for (int i = 0;i < s.size();i++) {
            ++count[s[i] - 'a'];
        }

        for (int i = 0;i < s.size();i++) {
            --count[s[i] - 'a'];

            while (!stk.empty() && stk.top() - s[i] > 0 && count[stk.top() - 'a'] >= 1 && check[s[i] - 'a'] < 1) {
                --check[stk.top() - 'a'];
                stk.pop();
                cout << endl;
            }

            if (stk.empty() ||   check[s[i] - 'a'] < 1) {
                stk.push(s[i]);
                ++check[s[i] - 'a'];
            }
        }

        string ans;
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};


int main() {
    Solution s;
    s.removeDuplicateLetters("cbacdcbc");
    return 0;
}