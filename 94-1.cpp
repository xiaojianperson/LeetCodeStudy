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
        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode> stk;
        stk.push(*root);

        while (!stk.empty()) {
            while (root != nullptr) {
                stk.push(*root);
                root = root->left;
            }
            root = &stk.top();
            stk.pop();
            ans.push_back(root->val);
            root = root->right;
        }

        ans.pop_back();
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    // Call the inorderTraversal method and print the result
    vector<int> inorder = solution.inorderTraversal(root);
    cout << "Inorder traversal: ";
    for (int value : inorder) {
        cout << value << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory for the binary tree
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}