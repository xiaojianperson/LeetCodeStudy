#include <vector>
#include <string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int count = 1;
        vector<vector<int>> check(m, vector<int>(n, 1));

        bool ans = false;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == word[0]) {
                    check[i][j] = 0;
                    function(check, board, i, j, word, count, ans, m, n);
                    check[i][j] = 1;
                }

            }
        }

        return ans;
    }

    void function(vector<vector<int>>& check, vector<vector<char>>& board, int& i, int& j, string& word, int& count, bool& ans, int& m, int& n) {
        if (count == word.size()) {
            ans = true;
            return;
        }

        if (i + 1 < m && board[i + 1][j] == word[count] && check[i + 1][j] == 1) {
            ++i;
            check[i][j] = 0;
            ++count;
            function(check, board, i, j, word, count, ans, m, n);
            --count;
            check[i][j] = 1;
            --i;
        }
        if (i - 1 >= 0 && board[i - 1][j] == word[count] && check[i - 1][j] == 1) {
            // 向上搜索
            --i; // 更新 i 值
            check[i][j] = 0; // 标记已访问过该位置
            ++count;
            function(check, board, i, j, word, count, ans, m, n); // 递归调用，继续向上匹配单词
            --count;
            check[i][j] = 1; // 恢复标记
            ++i; // 回溯
        }

        if (j + 1 < n && board[i][j + 1] == word[count] && check[i][j + 1] == 1) {
            // 向右搜索
            ++j; // 更新 j 值
            check[i][j] = 0; // 标记已访问过该位置
            ++count;
            function(check, board, i, j, word, count, ans, m, n); // 递归调用，继续向右匹配单词
            --count;
            check[i][j] = 1; // 恢复标记
            --j; // 回溯
        }

        if (j - 1 >= 0 && board[i][j - 1] == word[count] && check[i][j - 1] == 1) {
            // 向左搜索
            --j; // 更新 j 值
            check[i][j] = 0; // 标记已访问过该位置
            ++count;
            function(check, board, i, j, word, count, ans, m, n); // 递归调用，继续向左匹配单词
            --count;
            check[i][j] = 1; // 恢复标记
            ++j; // 回溯
        }
    }
};

int main() {
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    string word = "ABCCED";

    Solution s = Solution();

    if (s.exist(board, word)) {
        cout << "Word exists in the board." << endl;
    }
    else {
        cout << "Word does not exist in the board." << endl;
    }

    return 0;
}
