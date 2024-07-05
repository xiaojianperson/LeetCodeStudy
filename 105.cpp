#include <iostream>
#include <vector>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return function(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* function(vector<int>& preorder, vector<int>& inorder, int count, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int locationI = -1;
        int locationP = -1;

        for (int i = count;i < preorder.size() && locationI == -1;i++) {
            for (int j = left;j <= right && locationI == -1;j++) {
                if (preorder[i] == inorder[j]) {
                    locationP = i;
                    locationI = j;
                }
            }
        }

        TreeNode* ans = new TreeNode(preorder[locationP]);

        ans->left = function(preorder, inorder, locationP + 1, left, locationI - 1);
        ans->right = function(preorder, inorder, locationP + 1, locationI + 1, right);
        return ans;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            std::cout << node->val << " ";

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
}

int main() {
    Solution solution;
    std::vector<int> preorder = { 3, 9, 20, 15, 7 };
    std::vector<int> inorder = { 9, 3, 15, 20, 7 };
    TreeNode* root = solution.buildTree(preorder, inorder);

    // 在这里可以添加打印树的代码进行验证
    std::cout << "Constructed Binary Tree: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}
