#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(std::string s) {
        string ans;
        if (s.empty()) {
            return ans;
        }

        function(s, ans);
        return ans;
    }

    void function(string s, string& ans) {
        int num = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = (10 * num + (s[i] - '0'));
            }

            if (s[i] == '[') {
                int count = 1;
                string newS;
                int l = i + 1;

                while (count) {
                    newS += s[l];
                    ++l;

                    if (s[l] == '[') {
                        count++;
                    }

                    if (s[l] == ']') {
                        count--;
                    }
                }

                for (int j = 0;j < num;j++) {
                    function(newS, ans);
                }
                
                num = 0;
                i += (1 + newS.size());
            }

            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
        }
    }
};

int main() {
    Solution solution;
    std::string encodedString = "100[leetcode]";
    std::string decodedString = solution.decodeString(encodedString);
    std::cout << "Decoded string: " << decodedString << std::endl;
    return 0;
}