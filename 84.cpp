#include <vector>
#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        if (heights.empty()) {
            return ans;
        }
        stack<int> s;

        for (int i = 0;i < heights.size();i++) {
            if (s.empty() || heights[i] > heights[s.top()]) {
                s.push(i);
            }

            while (!s.empty() && heights[i] < heights[s.top()]) {
                int location = s.top();
                ans = max(ans, heights[s.top()] * (i - s.top()));
                s.pop();

                if (s.empty() || heights[i] > heights[s.top()]) {
                    heights[location] = heights[i];
                    s.push(location);
                }
            }
        }

        int length = heights.size();

        while (!s.empty()) {
            ans = max(ans, heights[s.top()] * (length - s.top()));
            s.pop();
        }

        return ans;
    }
};

int main() {
    // 创建 Solution 类的一个实例
    Solution sol;

    // 初始化测试数据
    vector<int> testHeights = { 4,2,0,3,2,5 };

    // 调用 largestRectangleArea 方法计算最大矩形面积
    int largestArea = sol.largestRectangleArea(testHeights);

    // 输出最大矩形面积的结果
    cout << "给定高度数组中最大矩形面积是: " << largestArea << endl;

    return 0; // 程序执行成功
}