#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int first = 0, second = 0, firstValue = 0, secondValue = 0;

        while (first < version1.size() || second < version2.size()) {
            firstValue = 0;
            secondValue = 0;

            while (first < version1.size() && version1[first] != '.') {
                firstValue = firstValue * 10 + (version1[first] - '0');
                ++first;
            }

            while (second < version2.size() && version2[second] != '.') {
                secondValue = secondValue * 10 + (version2[second] - '0');
                ++second;
            }

            if (firstValue == secondValue) {
                ++first;
                ++second;
            }
            else {
                break;
            }
        }

        return (firstValue > secondValue) - (firstValue < secondValue);
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    cout << solution.compareVersion("1.2147483647","1.2147483647");
    return 0;
}