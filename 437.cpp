#include <iostream>
#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> prefix;
        prefix[0]++;
        function(root, targetSum, prefix, ans);
        return ans;
    }

    void function(TreeNode* root, int targetSum, unordered_map<long long, int>& prefix, int& ans) {
        if (root == nullptr) {
            return;
        }

        if (prefix[targetSum - root->val] > 0) {
            ans += prefix[targetSum - root->val];
        }

        unordered_map<long long, int> tempPrefix(prefix);

        for (const auto& pair : tempPrefix) {
            if (pair.second) {
                prefix[pair.first + root->val] += pair.second;
                prefix[pair.first] -= pair.second;
            }
        }

        prefix[0]++;

        function(root->left, targetSum, prefix, ans);
        function(root->right, targetSum, prefix, ans);
    }   
};

TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// int main() {
//     // 创建示例二叉树
//     TreeNode* root = createNode(10);
//     root->left = createNode(5);
//     root->right = createNode(-3);
//     root->left->left = createNode(3);
//     root->left->right = createNode(2);
//     root->right->right = createNode(11);
//     root->left->left->left = createNode(3);
//     root->left->left->right = createNode(-2);
//     root->left->right->right = createNode(1);

//     // 调用路径总和函数
//     Solution solution;
//     int targetSum = 8;
//     int result = solution.pathSum(root, targetSum);

//     std::cout << "Path sum: " << result << std::endl;

//     return 0;
// }

int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(-2);
    root->left->left->left = new TreeNode(-1);

    // 调用路径总和函数
    Solution solution;
    int targetSum = -1;
    int result = solution.pathSum(root, targetSum);

    std::cout << "Path sum: " << result << std::endl;

    return 0;
}


