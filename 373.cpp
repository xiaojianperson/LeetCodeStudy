#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
            };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 0;i < min((int)nums1.size(), k);i++) {
            pq.emplace(pair<int, int>{i, 0});
        }

        vector<vector<int>> ans;

        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();

            ans.emplace_back(vector<int>{nums1[x], nums2[y]});
            if (y + 1 < nums2.size()) {
                pq.emplace(pair<int, int>{x, y + 1});
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}