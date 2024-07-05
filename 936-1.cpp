#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        int temp = 1;
        vector<int> ans;

        while (count != temp) {
            temp = count;
            bool check = false;
            for (int i = 0;i <= target.size() - stamp.size();i++) {
                int j = 0;
                while (j < stamp.size()) {
                    if (target[i] != stamp[j] && target[i] != '?') {
                        break;
                    }
                    ++i;
                    ++j;
                }

                if (j == stamp.size()) {
                    for (int k = i - j + 1;k <= i;k++) {
                        if (target[k] != '?') {
                            target[k] = '?';
                            ++count;
                        }

                    }
                }
            }
        }

        if (count < target.size()) {
            return vector<int>();

        }
        else {
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};

int main() {
    Solution s;
    s.movesToStamp("abca", "aabcaca");
    return 0;
}