#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int count = 1;
        int check = 2;

        while (count) {
            count = 0;

            for (int i = 0;i < grid.size();i++) {
                for (int j = 0;j < grid[0].size();j++) {
                    if (grid[i][j] == check) {
                        function(grid, i, j, check, count);
                    }
                }
            }

            check++;
            ans += count;
        }

        for (int i = 0;i < grid.size();i++) {
                for (int j = 0;j < grid[0].size();j++) {
                    if (grid[i][j] == 1) {
                        ans=-1;
                    }
                }
            }

        return ans;
    }

    void function(vector<vector<int>>& grid, int i, int j, int check, int& count) {
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            grid[i - 1][j] = check + 1;
            count = 1;
        }

        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            grid[i + 1][j] = check + 1;
            count = 1;
        }

        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            grid[i][j - 1] = check + 1;
            count = 1;
        }

        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
            grid[i][j + 1] = check + 1;
            count = 1;
        }
    }
};

int main() {
    // std::vector<std::vector<int>> grid = {
    //     {2, 1, 1},
    //     {1, 1, 0},
    //     {0, 1, 1}
    // };

    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };

    Solution solution;

    int minutes = solution.orangesRotting(grid);

    if (minutes != -1) {
        std::cout << "Time taken for all oranges to rot: " << minutes << " minutes\n";
    }
    else {
        std::cout << "Not all oranges can rot\n";
    }

    return 0;
}
