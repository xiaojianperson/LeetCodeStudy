#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int xCheck = 0, yCheck = 0;
        for (int i = 0;i < matrix[0].size();i++) {
            if (matrix[0][i] == 0) {
                xCheck = 1;
            }
        }

        for (int i = 0;i < matrix.size();i++) {
            if (matrix[i][0] == 0) {
                yCheck = 1;
            }
        }

        for (int i = 1;i < matrix.size();i++) {
            for (int j = 1;j < matrix[0].size();j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1;i < matrix[0].size();i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1;j < matrix.size();j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 1;i < matrix.size();i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1;j < matrix[0].size();j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (xCheck == 1) {
            for (int i = 0;i < matrix[0].size();i++) {
                matrix[0][i] = 0;
            }
        }

        if (yCheck == 1) {
            for (int i = 0;i < matrix.size();i++) {
                matrix[i][0] = 0;
            }
        }

        cout << endl;
    }
};

int main() {
    Solution sol;

    // 创建一个示例矩阵
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    // 调用 setZeroes 方法
    sol.setZeroes(matrix);

    // 打印修改后的矩阵
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}