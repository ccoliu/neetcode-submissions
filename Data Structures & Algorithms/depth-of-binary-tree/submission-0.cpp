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
    int solve(TreeNode* node, int level) {
        if (!node) return level;
        return max(solve(node->left, level + 1), solve(node->right, level + 1));
    }
    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};
