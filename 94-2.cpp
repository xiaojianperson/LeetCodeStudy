#include<iostream>
#include<vector>
#include<stack>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* preNode;
        vector<int> ans;

        while (root != nullptr) {
            while (root->left != nullptr) {
                preNode = root->left;
                while (preNode->right != nullptr) {
                    preNode = preNode->right;
                }
                preNode->right = root;
                root = root->left;
                if (root->left == nullptr) {
                    preNode = root;
                }
            }

            ans.push_back(root->val);

            if (root->right != nullptr && root->right->left == preNode) {
                preNode = root;
                root = root->right;

                preNode->right = nullptr;
                preNode = root;

                ans.push_back(root->val);
            }


            root = root->right;
        }

        return ans;
    }
};

TreeNode* buildCompleteBinaryTree() {
    // 构建根节点
    TreeNode* root = new TreeNode(1);

    // 构建树的第一层
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // 构建树的第二层
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 构建树的第三层
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    return root;
}

TreeNode* buildCompleteBinaryTree1() {
    // 构建根节点
    TreeNode* root = new TreeNode(2);

    // 构建树的第一层
    root->left = new TreeNode(3);

    // 构建树的第二层
    root->left->left = new TreeNode(1);

    // root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->left = new TreeNode(6);

    return root;
}

int main() {
    TreeNode* root = buildCompleteBinaryTree();
    Solution solution;

    // Call the inorderTraversal method and print the result
    vector<int> inorder = solution.inorderTraversal(root);
    cout << "Inorder traversal: ";
    for (int value : inorder) {
        cout << value << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory for the binary tree
    return 0;
}