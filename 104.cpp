#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        int maxDepth1 = 0;
        dfs(root, depth, maxDepth1);
        return maxDepth1;
    }

    void dfs(TreeNode* root, int depth, int& maxDepth1) {
        depth++;
        maxDepth1 = max(depth, maxDepth1);
        if (root->left != nullptr) {
            dfs(root->left, depth, maxDepth1);

        }
        if (root->right != nullptr) {
            dfs(root->right, depth, maxDepth1);
        }
        depth--;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "The maximum depth of the binary tree is: " << depth << endl;

    return 0;
}
