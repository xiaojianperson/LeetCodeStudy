#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsCount1;

        for (int i = 0;i < words.size();i++) {
            ++wordsCount1[words[i]];
        }

        unordered_map<string, int> wordsCount2 = wordsCount1;

        vector<int> ans;

        int length = words[0].size();

        for (int i = 0;i < length;i++) {
            int count = words.size();
            wordsCount1 = wordsCount2;

            for (int left = i, right = i;s.size() > (words.size() * length) && left < s.size() - (words.size() * length);right += length) {
                string cur = s.substr(right, length);
                if (wordsCount1[cur] > 0) {
                    --wordsCount1[cur];
                    --count;
                    if (count == 0) {
                        ans.push_back(left);
                        left = right + length;
                        wordsCount1 = wordsCount2;
                        count = words.size();
                    }
                }
                else {
                    left = right;
                    right -= length;
                    wordsCount1 = wordsCount2;
                    count = words.size();
                }
            }
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    string s = "barfoofoobarthefoobarman";
    vector<string> arr = { "bar","foo","the" };
    solution.findSubstring(s, arr);
    return 0;
}