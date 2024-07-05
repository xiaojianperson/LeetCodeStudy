#include <iostream>
#include <stack>
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode*> nodes;
        function(nodes, root);
        nodes.pop();

        while (!nodes.empty()) {
            root->right = nodes.top();
            nodes.pop();
            root = root->right;
        }
    }

    void function(stack<TreeNode*>& nodes, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        function(nodes, root->right);
        function(nodes, root->left);
        nodes.push(root);
        root->left = nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root);

    TreeNode* current = root;
    std::cout << "Flattened tree: ";
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->right;
    }
    std::cout << std::endl;

    return 0;
}
