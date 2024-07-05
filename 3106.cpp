#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0;i < s.size();i++) {
            if (k == 0) {
                break;
            }
            int location = min(s[i] - 'a', 'a' + 26 - s[i]);
            if (location <= k) {
                s[i] = 'a';
                k -= location;
            }
            else {
                s[i] = min(s[i] - k, (s[i] + k) - 26 + 'a');
                k = 0;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    s.getSmallestString("aawbc", 4);
    return 0;
}