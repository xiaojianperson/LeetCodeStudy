#include <iostream>
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        bool ans = true;
        check(root->left, root->right, ans);
        return ans;
    }

    int check(TreeNode* left, TreeNode* right, bool& ans) {
        if (ans) {
            if (left == nullptr && right == nullptr) {
                return 0;
            }
            if (left != nullptr && right != nullptr && left->val == right->val) {
                check(left->left, right->right, ans);
                check(left->right, right->left, ans);
                return 0;
            }
            ans = false;
            return 1;
        }
        return 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool symmetric = solution.isSymmetric(root);

    if (symmetric) {
        cout << "The binary tree is symmetric." << endl;
    }
    else {
        cout << "The binary tree is not symmetric." << endl;
    }

    return 0;
}
