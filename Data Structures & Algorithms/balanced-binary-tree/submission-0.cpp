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
    int getLevel(TreeNode* node) {
        if (!node) return 0;

        int leftheight = getLevel(node->left);
        if (leftheight == -1) return -1;

        int rightheight = getLevel(node->right);
        if (rightheight == -1) return -1;

        if (abs(rightheight - leftheight) > 1) return -1;

        return max(rightheight, leftheight) + 1;       
    }
    bool isBalanced(TreeNode* root) {
        return getLevel(root) != -1;
    }
};
