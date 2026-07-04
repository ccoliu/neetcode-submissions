/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inverse(TreeNode* node) {
        TreeNode* tmp = nullptr;

        if (node->left && node->right) {
            tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            inverse(node->left);
            inverse(node->right);
        }
        else if (node->left) {
            node->right = node->left;
            node->left = nullptr;
            inverse(node->right);
        }
        else if (node->right) {
            node->left = node->right;
            node->right = nullptr;
            inverse(node->left);
        }
        else return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        inverse(root);
        return root;
    }
};
