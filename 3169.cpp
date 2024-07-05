#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> check;
        check.emplace_back(meetings[0]);

        for (int i = 1;i < meetings.size();i++) {
            bool isChange = false;
            for (int j = 0;j < check.size();j++) {
                if (meetings[i][0] > check[j][1] || meetings[i][1] < check[j][0]) {
                    continue;
                }
                // else if ((meetings[i][0] <= check[j][0] && meetings[i][1] >= check[j][1]) || (meetings[i][0] >= check[j][0] && meetings[i][1] <= check[j][1])) {
                //     check[j][0] = min(meetings[i][0], check[j][0]);
                //     check[j][1] = max(meetings[i][1], check[j][1]);
                // }
                else {
                    check[j][0] = min(meetings[i][0], check[j][0]);
                    check[j][1] = max(meetings[i][1], check[j][1]);
                    isChange = true;
                    break;
                }
            }

            if (!isChange) {
                check.emplace_back(meetings[i]);
            }
        }

        int count = 0;
        for (int i = 0;i < check.size();i++) {
            count += (check[i][1] - check[i][0] + 1);
        }
        return days - count;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    // vector<vector<int>> meetings = { {6,11},{7,13},{8,9},{5,8},{3,13},{11,13},{1,3},{5,10},{8,13},{3,9} };
    vector<vector<int>> meetings = { {3,9},{7,16},{21,23},{22,33},{5,13},{10,23},{1,15} };
    // vector<vector<int>> meetings = { {5,7},{1,3},{9,10} };
    // vector<vector<int>> meetings = { {2,3},{3,5},{8,8} };
    solution.countDays(33, meetings);
    return 0;
}
