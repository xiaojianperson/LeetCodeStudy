#include<vector>
#include<iostream>
#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }

        vector<TreeNode*> arr;

        vector<vector<int>> ans;

        ans.emplace_back(vector<int>(1, root->val));

        int depth = 0;

        arr.emplace_back(root);



        while (!arr.empty()) {
            vector<TreeNode*> tem;

            for (int i = 0;i < arr.size();i++) {
                TreeNode* temNode = arr[arr.size() - 1 - i];

                if (temNode->left != nullptr && temNode->right != nullptr) {
                    tem.emplace_back(depth == 0 ? temNode->right : temNode->left);
                    tem.emplace_back(depth == 1 ? temNode->right : temNode->left);
                }
                else if (temNode->left != nullptr) {
                    tem.emplace_back(temNode->left);
                }
                else if (temNode->right != nullptr) {
                    tem.emplace_back(temNode->right);
                }
            }

            if (!tem.empty()) {
                ans.emplace_back(vector<int>());
            }


            for (int i = 0;i < tem.size();i++) {
                ans[ans.size() - 1].emplace_back(tem[i]->val);
            }

            arr = tem;

            depth = (++depth) % 2;
        }

        return ans;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    return 0;
}