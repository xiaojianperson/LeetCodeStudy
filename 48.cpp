#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();

        for (int i = 0;i < length - 1;i++) {
            for (int j = 0;j < length - i - 1;j++) {
                swap(matrix[i][j], matrix[length - 1 - j][length - 1 - i]);
            }
        }

        for (int i = 0;i < length / 2;i++) {
            for (int j = 0;j < length;j++) {
                swap(matrix[i][j], matrix[length - 1 - i][j]);;
            }
        }
    }
};