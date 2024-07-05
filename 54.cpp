#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count = matrix.size() * matrix[0].size();
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        int a = 0, b = matrix.size() - 1, c = 0, d = matrix[0].size() - 1;
        int direction[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        int change = 0;

        while (count != 0) {
            ans.push_back(matrix[i][j]);

            int x = i + direction[k][0];
            int y = j + direction[k][1];

            if (x >= a && x <= b && y >= c && y <= d) {
            }
            else {
                ++k;
                k %= 4;
                x = i + direction[k][0];
                y = j + direction[k][1];
            }

            i = x;
            j = y;
            --count;

            if (i == a && j == d && change == 0) {
                ++a;
                ++change;

            }
            if (i == b && j == d && change == 1) {
                --d;
                ++change;

            }
            if (i == b && j == c && change == 2) {
                --b;
                ++change;;

            }
            if (i == a && j == c && change == 3) {
                ++c;
                change = 0;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> arr = { {1,2,3,4,5},
                                {6,7,8,9,10},
                                {11,12,13,14,15},
                                {16,17,18,19,20},
                                {21,22,23,24,25} };
    Solution s;
    s.spiralOrder(arr);
    cout<<"Hello world！"<<endl;
    return 0;
}