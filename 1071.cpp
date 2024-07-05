#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string& s1 = str1.size() >= str2.size() ? str1 : str2;
        string& s2 = str1.size() >= str2.size() ? str2 : str1;

        string ans;

        for (int i = s2.size();i >= 1;i--) {
            if (s2.size() % i == 0 && s1.size() % i == 0) {
                string check1 = s2.substr(0, i);
                string check2;

                for (int j = 0;j < s2.size() / i;j++) {
                    check2 += check1;
                }

                if (check2 == s2) {
                    string check3;
                    for (int j = 0;j < s1.size() / i;j++) {
                        check3 += check1;
                    }
                    if (check3 == s1) {
                        ans = check1;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    s.gcdOfStrings("ABABABAB", "ABAB");
    return 0;
}