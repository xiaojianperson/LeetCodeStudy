#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        getDepth(root);
        return ans;
    }

    int getDepth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l=getDepth(root->left);
        int r=getDepth(root->right);
        ans=max(l+r,ans);
        return max(l,r)+1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << result << endl;

    return 0;
}
