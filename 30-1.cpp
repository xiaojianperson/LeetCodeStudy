#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length = words[0].size();

        unordered_map<string, int> wordsCount1;
        unordered_map<string, int> wordsCount2;

        for (int i = 0;i < words.size();i++) {
            ++wordsCount1[words[i]];
            ++wordsCount2[words[i]];
        }

        vector<int> ans;

        for (int i = 0;i < length;i++) {
            string res;
            wordsCount1 = wordsCount2;
            int total = words.size();

            for (int left = i, right = i;s.size() >= total * length && left <= s.size() - total * length;left += length) {
                //删除左边移出窗口的元素
                if (left >= length) {
                    res = s.substr(left - length, length);
                    if (wordsCount2[res] > 0) {
                        ++wordsCount1[res];
                        ++total;
                    }
                }

                res = s.substr(left, length);
                if (wordsCount2[res] == 0) {
                    continue;
                }

                right = max(right, left);

                //添加右边符合条件的元素
                while (right <= s.size() - length && total > 0) {
                    res = s.substr(right, length);
                    right += length;

                    if (wordsCount1[res] <= 0) {
                        right -= length;
                        break;
                    }

                    --wordsCount1[res];
                    --total;
                }

                if (total == 0) {
                    ans.emplace_back(left);
                }
            }
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    string s = "mississippi";
    vector<string> arr = { "mississippis" };
    solution.findSubstring(s, arr);
    return 0;
}