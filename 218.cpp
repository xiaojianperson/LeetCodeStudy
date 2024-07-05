#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto comp = [&buildings](int& x, int& y) {
            return buildings[x][2] < buildings[y][2];
            };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        vector<int> nodes;
        for (int i = 0;i < buildings.size();i++) {
            nodes.emplace_back(buildings[i][0]);
            nodes.emplace_back(buildings[i][1]);
        }
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        int location = 0;

        for (int i = 0;i < nodes.size();i++) {
            if (i == nodes.size() - 1 || nodes[i] != nodes[i + 1]) {
                if (location < buildings.size() && nodes[i] == buildings[location][0]) {
                    pq.emplace(location);

                    int skyLine = pq.top();
                    if (buildings[location][2] == buildings[skyLine][2]) {
                        if (ans.size() == 0 || buildings[location][2] != ans[ans.size() - 1][1]) {
                            ans.push_back(vector<int>{nodes[i], buildings[location][2]});
                        }
                    }

                    if (location < buildings.size() - 1)
                        ++location;
                }
                else if (!pq.empty()) {
                    while (!pq.empty() && buildings[pq.top()][1] <= nodes[i]) {
                        pq.pop();
                    }
                    int skyLine = pq.top();
                    if (nodes[i] == buildings[skyLine][1]) {

                        pq.pop();

                        if (!pq.empty()) {
                            if (buildings[pq.top()][2] != ans[ans.size() - 1][1]) {
                                ans.push_back(vector<int>{nodes[i], buildings[pq.top()][2]});
                            }

                        }
                        else {
                            ans.push_back(vector<int>{nodes[i], 0});
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> temp = { {0,2,3},{2,5,3} };
    Solution s;
    s.getSkyline(temp);
    return 0;
}