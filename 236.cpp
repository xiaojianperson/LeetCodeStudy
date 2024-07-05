#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* nodeLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* nodeRight = lowestCommonAncestor(root->right, p, q);

        if ((nodeLeft == p || nodeLeft == q) && (nodeRight == p || nodeRight == q)) {
            return root;
        }

        if (nodeLeft == p || nodeLeft == q || nodeLeft != nullptr) {
            return nodeLeft;
        }

        if (nodeRight == p || nodeRight == q || nodeRight != nullptr) {
            return nodeRight;
        }

        return nullptr;
    }
};

// int main() {
//     // 创建示例二叉树
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);
//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(0);
//     root->right->right = new TreeNode(8);
//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);

//     // 创建 Solution 实例
//     Solution solution;

//     // 查找最近公共祖先并输出结果
//     TreeNode* result = solution.lowestCommonAncestor(root, root->left, root->left->right->right);
//     std::cout << "Lowest common ancestor: " << result->val << std::endl;

//     return 0;
// }

int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(8);

    // 创建 Solution 实例
    Solution solution;

    // 查找最近公共祖先并输出结果
    TreeNode* result = solution.lowestCommonAncestor(root, root->left->right, root->left->left->left);
    std::cout << "Lowest common ancestor: " << result->val << std::endl;

    return 0;
}
