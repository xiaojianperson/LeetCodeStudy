#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordsBegin(wordList.begin(), wordList.end());

        if (wordsBegin.empty() || wordsBegin.find(endWord) == wordsBegin.end()) return 0;

        wordsBegin.erase(beginWord);

        queue<string> queBegin;
        queBegin.push(beginWord);

        wordsBegin.erase(beginWord);

        int stepBegin = 1;

        unordered_set<string> wordsEnd(wordList.begin(), wordList.end());

        wordsEnd.erase(endWord);

        queue<string> queEnd;
        queEnd.push(endWord);

        wordsEnd.erase(endWord);

        int stepEnd = 1;

        while (!queBegin.empty() && !queEnd.empty()) {
            // 找到没有被访问过, 而且能够由当前单词转换而成的单词
            int n = queBegin.size();

            int m = queEnd.size();

            if (n <= m) {
                // 每一轮(每一层step加个1)
                while (n--) {
                    string curWord = queBegin.front();
                    queBegin.pop();

                    // 当前单词的每个字符都替换成其他的25个字符, 然后在单词表中查询
                    // 是不是包含转换后的单词
                    // 这里千万不能遍历单词表, 因为单词表很长, 而哈希表使用的红黑树
                    // 的查询效率比遍历单词表高很多
                    for (int i = 0; i < curWord.size(); ++i) {
                        char originalChar = curWord[i];

                        for (int j = 0; j < 26; ++j) {
                            if (char('a' + j) == originalChar) continue;
                            curWord[i] = (char)('a' + j);

                            if (wordsBegin.find(curWord) != wordsBegin.end()) {
                                if (wordsEnd.find(curWord) == wordsEnd.end()) return stepBegin + stepEnd;
                                else {
                                    queBegin.push(curWord);
                                    wordsBegin.erase(curWord);
                                }
                            }
                        }

                        curWord[i] = originalChar;
                    }
                }

                ++stepBegin;
            }
            else {
                // 每一轮(每一层step加个1)
                while (m--) {
                    string curWord = queEnd.front();
                    queEnd.pop();

                    // 当前单词的每个字符都替换成其他的25个字符, 然后在单词表中查询
                    // 是不是包含转换后的单词
                    // 这里千万不能遍历单词表, 因为单词表很长, 而哈希表使用的红黑树
                    // 的查询效率比遍历单词表高很多
                    for (int i = 0; i < curWord.size(); ++i) {
                        char originalChar = curWord[i];

                        for (int j = 0; j < 26; ++j) {
                            if (char('a' + j) == originalChar) continue;
                            curWord[i] = (char)('a' + j);

                            if (wordsEnd.find(curWord) != wordsEnd.end()) {
                                if (wordsBegin.find(curWord) == wordsBegin.end()) return stepBegin + stepEnd;
                                else {
                                    queEnd.push(curWord);
                                    wordsEnd.erase(curWord);
                                }
                            }
                        }

                        curWord[i] = originalChar;
                    }
                }

                ++stepEnd;
            }
        }

        return 0;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<string> arr = { "a","b","c" };
    cout << solution.ladderLength("a", "c", arr);
    return 0;
}