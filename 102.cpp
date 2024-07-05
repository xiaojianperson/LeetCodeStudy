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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root);
        TreeNode* node;


        while (!q1.empty() || !q2.empty()) {
            ans.push_back(vector<int>());
            while (!q1.empty()) {
                node = q1.front();
                q1.pop();

                ans.back().push_back(node->val);

                if (node->left != nullptr) {
                    q2.push(node->left);
                }
                if (node->right != nullptr) {
                    q2.push(node->right);
                }
            }
            if(!q2.empty())
            ans.push_back(vector<int>());

            while (!q2.empty()) {
                node = q2.front();
                q2.pop();

                ans.back().push_back(node->val);

                if (node->left != nullptr) {
                    q1.push(node->left);
                }
                if (node->right != nullptr) {
                    q1.push(node->right);
                }
            }
        }

        return ans;
    }
};

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 调用层次遍历函数
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // 输出结果
    for (vector<int>& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
