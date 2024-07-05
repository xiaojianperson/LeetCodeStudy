#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) {
            return true;
        }

        int left = 0;
        int right = nums.size() - 1;
        int firstScore = 0;
        int scondeScore = 0;

        while (left < right) {
            int letfValue = nums[left] - max(nums[min(left + 1, (int)nums.size() - 1)], nums[right]);
            int rightValue = nums[right] - max(nums[left], nums[max(0, right - 1)]);

            if (letfValue >= rightValue) {
                firstScore += nums[left];
                left++;
            }
            else {
                firstScore += nums[right];
                right--;
            }

            letfValue = nums[left] - max(nums[min(left + 1, (int)nums.size() - 1)], nums[right]);
            rightValue = nums[right] - max(nums[left], nums[max(0, right - 1)]);

            if (letfValue >= rightValue) {
                scondeScore += nums[left];
                left++;
            }
            else {
                scondeScore += nums[right];
                right--;
            }
        }

        if (left == right) {
            firstScore += nums[left];
        }

        return firstScore >= scondeScore;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    vector<int> arr = { 3606449,6,5,9,452429,7,9580316,9857582,8514433,9,6,6614512,753594,5474165,4,2697293,8,7,1 };
    solution.predictTheWinner(arr);
    return 0;
}