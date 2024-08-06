#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
};

class neighborSum {
public:
    int x, y;
    vector<vector<int>>* neighborSumPtr;

    neighborSum(vector<vector<int>>& grid) {
        x = grid[0].size();
        y = grid.size();
        neighborSumPtr = &grid;
    }

    int adjacentSum(int value) {
        int resX, resY;

        int a = 0, b = 0, c = 0, d = 0;

        for (int i = 0;i < y;i++) {
            for (int j = 0;j < x;j++) {
                auto ptr = *this->neighborSumPtr;
                if (ptr[i][j] == value) {
                    resX = j;
                    resY = i;

                    if (resY - 1 >= 0) {
                        a = ptr[resY - 1][resX];
                    }

                    if (resX - 1 >= 0) {
                        b = ptr[resY][resX - 1];
                    }

                    if (resX + 1 < x) {
                        c = ptr[resY][resX + 1];
                    }

                    if (resY + 1 < y) {
                        d = ptr[resY + 1][resX];
                    }
                }
            }
        }

        return  a + b + c + d;
    }

    int diagonalSum(int value) {
        int resX, resY;

        int a = 0, b = 0, c = 0, d = 0;

        for (int i = 0;i < y;i++) {
            for (int j = 0;j < x;j++) {
                auto ptr = *this->neighborSumPtr;
                if (ptr[i][j] == value) {
                    resX = j;
                    resY = i;

                    if (resY - 1 >= 0 && resX - 1 >= 0) {
                        a = ptr[resY - 1][resX - 1];
                    }

                    if (resX + 1 < x && resY - 1 >=0) {
                        b = ptr[resY - 1][resX + 1];
                    }

                    if (resX - 1 >= 0 && resY + 1 < y) {
                        c = ptr[resY + 1][resX - 1];
                    }

                    if (resX + 1 < x && resY + 1 < y) {
                        d = ptr[resY + 1][resX + 1];
                    }

                }
            }
        }

        return a + b + c + d;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main() {
    // 创建一个示例网格
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 创建neighborSum类的实例
    neighborSum* obj = new neighborSum(grid);

    // 测试adjacentSum方法
    int value1 = 5; // 假设我们要找的值是5
    int sum1 = obj->adjacentSum(value1);
    cout << "Sum of adjacent values for " << value1 << " is: " << sum1 << endl;

    // 测试diagonalSum方法
    int value2 = 5; // 同样假设我们要找的值是5
    int sum2 = obj->diagonalSum(value2);
    cout << "Sum of diagonal values for " << value2 << " is: " << sum2 << endl;

    // 清理动态分配的内存
    delete obj;

    return 0;
}