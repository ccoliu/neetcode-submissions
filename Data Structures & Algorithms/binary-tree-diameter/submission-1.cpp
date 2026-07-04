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
    int solve(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(solve(node->left), solve(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int dia = left + right;
        int sub = diameterOfBinaryTree(root->left) + diameterOfBinaryTree(root->right);

        return max(dia, sub);
    }
};
