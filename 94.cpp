#include <vector>
#include <iostream>
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* prenode = new TreeNode(0);

        while (root != nullptr) {
            if (root->left != nullptr) {
                if (prenode->right == root) {
                    ans.push_back(root->val);
                    TreeNode* node1 = root;
                    root = root->right;
                    prenode->right = nullptr;
                    prenode = node1;
                }
                else {
                    prenode = root->left;
                    while (prenode->right != nullptr && prenode->right != root) {
                        prenode = prenode->right;
                    }

                    prenode->right = root;
                    root = root->left;
                }
            }
            else {
                ans.push_back(root->val);
                TreeNode* node1 = root;
                root = root->right;
                prenode->right = nullptr;
                prenode = root;

            }
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

int main() {
    // 创建示例二叉树
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = nullptr;
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // 创建 Solution 对象
    Solution solution;

    // 调用中序遍历函数
    std::vector<int> result = solution.inorderTraversal(root);

    // 打印中序遍历结果
    std::cout << "Inorder traversal result: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 释放内存
    // delete root->right->left;
    // delete root->right;
    // delete root;

    return 0;
}
