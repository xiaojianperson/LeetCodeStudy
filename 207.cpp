#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> check(numCourses, vector<int>(1, -1));

        for (int i = 0;i < prerequisites.size();i++) {
            check[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        bool check1 = true;

        while (check1) {
            check1 = false;
            for (int i = 0;i < check.size();i++) {
                // if (check[i] == vector<int>(check[i].size(), -1)){
                //     check1 = true;
                //     break;;
                // }      

                for (int j = 1;j < check[i].size();j++) {
                    if (check[i][j] != -1) {
                        if (check[check[i][j]] == vector<int>(check[check[i][j]].size(), -1)) {
                            check[i][j] = -1;
                            check1 = true;
                        }
                    }
                }
            }
        }

        bool ans = true;

        for (int i = 0;i < check.size();i++) {
            for (int j = 0;j < check[i].size();j++) {
                if (check[i][j] != -1) {
                    ans = false;
                    break;;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int numCourses = 3;
    // vector<vector<int>> prerequisites = { {1, 0}, {2, 1}, {3, 2}, {4, 3}, {1, 4} };
    // vector<vector<int>> prerequisites = { {1, 0} };
    vector<vector<int>> prerequisites = { {0, 1},{1,2},{0,2} };



    bool result = solution.canFinish(numCourses, prerequisites);

    if (result) {
        cout << "Can finish all courses." << endl;
    }
    else {
        cout << "Cannot finish all courses." << endl;
    }

    return 0;
}
