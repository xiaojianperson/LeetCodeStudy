#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0;i < flowerbed.size();i++) {
            if ((i - 1 == -1 || flowerbed[i - 1] != 1) &&
                (i + 1 == flowerbed.size() || flowerbed[i + 1] != 1) && flowerbed[i] != 1) {
                flowerbed[i] = 1;
                ++count;
            }
        }
        return n <= count;
    }
};

int main() {
    Solution s;
    // s.kidsWithCandies("ABABABAB", "ABAB");
    return 0;
}