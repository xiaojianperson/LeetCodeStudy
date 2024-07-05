#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //声明ans，当s长度小于10，直接返回ans
        vector<string> ans;
        if (s.size() < 10) {
            return ans;
        }

        //初始化滑动窗口num
        int num = 0;

        //初始化DNA哈希表
        unordered_map<char, int> DNA = { {'A',0},{'C',1},{'G',2},{'T',3} };

        //利用位运算处理滑动窗口
        //位运算处理步骤：先将num左移两位，后两位为00，再将num与当前DNA进行按位或运算，再将num与check进行按位与运算
        for (int i = 0;i < 10;i++) {
            num = (num << 2) | DNA[s[i]];
        }

        //声明滑动窗口计数哈希表
        unordered_map<int, int> count;

        ++count[num];

        for (int i = 10;i < s.size();i++) {
            num = ((num << 2) | DNA[s[i]]) & 0b00000000000011111111111111111111;
            if (++count[num] == 2) {
                ans.push_back(s.substr(i - 9, 10));
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}