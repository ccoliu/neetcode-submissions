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
        if (!node) return;
        swap(node->left, node->right);
        inverse(node->left);
        inverse(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        inverse(root);
        return root;
    }
};
