#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function(root, ans);
        return ans;
    }

    int function(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, function(root->left, ans)); // 只保留正数的贡献
        int right = max(0, function(root->right, ans)); // 只保留正数的贡献

        ans = max(ans, root->val + left + right); // 更新最大路径和

        return root->val + max(left, right); // 返回当前节点作为路径起点的最大路径和
    }
};

int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 创建 Solution 实例
    Solution solution;

    // 测试 maxPathSum 函数
    int result = solution.maxPathSum(root);
    std::cout << "Max path sum: " << result << std::endl;

    return 0;
}
