#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0, last = 1;
        int stSize = stamp.size(), taSize = target.size();
        vector<int> res;

        //count记录本次已经戳印的字符数量，last记录截止上次戳印的字符数量，如果两者相等，说明已经没有可以戳印的字符了
        while (count != last) {
            last = count;
            //遍历下一次戳印在target中的起始位置
            for (int start = 0;start <= taSize - stSize;start++) {
                bool operation = false;
                int i = start, j = 0;

                while (j < stSize) {
                    //?可以作为通配符参与比较，如果两个序列不相同，而且target相应字符不是？，则当前其实位置不能戳印
                    if (target[i] != stamp[j] && target[i] != '?') {
                        break;
                    }
                    //只有两个序列的当前字符相等而且不是'?'通配符,才视为一次有效的戳印匹配，（stamp中不可能存在'?'）
                    else if (target[i] == stamp[j]) {
                        operation = true;
                    }
                    i++, j++;
                }

                //如果本次戳印有效（匹配中含有非'?'字符，同时stamp完全匹配了）
                if (operation == true && j == stSize) {
                    //记录当前戳印起始位置
                    res.push_back(start);
                    //将非'?'字符变为‘?’字符，同时更新戳印的字符总数
                    while (--i >= start) {
                        if (target[i] != '?') {
                            count++;
                            target[i] = '?';
                        }
                    }
                }
            }
        }

        //如果不能完全的将target中的字符戳印，显然是失败的
        if (count != taSize) {
            return vector<int>();
        }
        else {
            //因为是戳印过程的逆过程，所以戳印顺序是反的，结果反向
            reverse(res.begin(), res.end());
            return res;
        }
    }
};