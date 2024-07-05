#include <iostream>
#include <algorithm>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return  function(root, LONG_MAX, LONG_MIN); // 调用递归函数进行判断

    }

    bool function(TreeNode* node, long minValue, long maxValue) {
        if (node->left != nullptr) {
            if (node->left->val >= node->val ||
                node->left->val >= minValue ||
                node->left->val <= maxValue) {
                return false;
            }
            return (node->left, node->val, maxValue);
        }

        if (node->right != nullptr) {
            if (node->right->val <= node->val ||
                node->right->val >= minValue ||
                node->right->val <= maxValue) {

                return false;
            }
            return function(node->right, minValue, node->val);
        }
    }
};

int main() {
    Solution solution; // 创建Solution类的实例

    // 构造二叉树
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool isValid = solution.isValidBST(root); // 调用isValidBST函数

    // 打印结果
    if (isValid) {
        cout << "The given binary tree is a valid binary search tree." << endl;
    }
    else {
        cout << "The given binary tree is not a valid binary search tree." << endl;
    }

    return 0;
}
