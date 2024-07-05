#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] >= 1) {

                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if (board[i - 1][j - 1] <= 0) {
                            --board[i - 1][j - 1];
                        }
                        else {
                            ++board[i - 1][j - 1];
                        }
                    }


                    if (i - 1 >= 0) {
                        if (board[i - 1][j] <= 0) {
                            --board[i - 1][j];
                        }
                        else {
                            ++board[i - 1][j];
                        }
                    }


                    if (i - 1 >= 0 && j + 1 < board[0].size()) {
                        if (board[i - 1][j + 1] <= 0) {
                            --board[i - 1][j + 1];
                        }
                        else {
                            ++board[i - 1][j + 1];
                        }
                    }


                    if (j - 1 >= 0) {
                        if (board[i][j - 1] <= 0) {
                            --board[i][j - 1];
                        }
                        else {
                            ++board[i][j - 1];
                        }
                    }


                    if (j + 1 < board[0].size()) {
                        if (board[i][j + 1] <= 0) {
                            --board[i][j + 1];
                        }
                        else {
                            ++board[i][j + 1];
                        }
                    }


                    if (i + 1 < board.size() && j - 1 >= 0) {
                        if (board[i + 1][j - 1] <= 0) {
                            --board[i + 1][j - 1];
                        }
                        else {
                            ++board[i + 1][j - 1];
                        }
                    }


                    if (i + 1 < board.size()) {
                        if (board[i + 1][j] <= 0) {
                            --board[i + 1][j];
                        }
                        else {
                            ++board[i + 1][j];
                        }
                    }


                    if (i + 1 < board.size() && j + 1 < board[0].size()) {
                        if (board[i + 1][j + 1] <= 0) {
                            --board[i + 1][j + 1];
                        }
                        else {
                            ++board[i + 1][j + 1];
                        }
                    }
                }
            }
        }

        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == -3) {
                    board[i][j] = 1;
                    continue;
                }
                if (board[i][j] == 1 || board[i][j] == 2) {
                    board[i][j] = 0;
                    continue;
                }
                if (board[i][j] > 4) {
                    board[i][j] = 0;
                    continue;
                }
                if (board[i][j] >= 1) {
                    board[i][j] = 1;
                }
                if (board[i][j] < 0) {
                    board[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> arr = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    Solution s;
    s.gameOfLife(arr);
    return 0;
}