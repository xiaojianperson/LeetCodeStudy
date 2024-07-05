#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        return function(root, 1, ans);
    }

    std::vector<int> function(TreeNode* root, int depth, std::vector<int>& ans) {
        if (root == nullptr) {
            return vector<int>(); // 返回空的vector
        }

        if (ans.size() < depth) {
            ans.push_back(root->val);
        }

        function(root->right, depth + 1, ans);
        function(root->left, depth + 1, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    std::vector<int> result = solution.rightSideView(root);

    std::cout << "Right side view of the tree: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
