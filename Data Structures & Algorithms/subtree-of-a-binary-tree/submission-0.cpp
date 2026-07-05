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
    bool validate(TreeNode* n, TreeNode* s, TreeNode* h) {
        if (!s && !n) return true;
        if (!n && s || !s && n) return false;

        if (n->val == s->val) {
            if (validate(n->left, s->left, h) && validate(n->right, s->right, h)) return true;
        }
        else {
            s = h;
        }

        return validate(n->left, s, h) || validate(n->right, s, h);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (root->val == subRoot->val) {
            if (validate(root->left, subRoot->left, subRoot) && validate(root->right, subRoot->right, subRoot)) return true;
        }

        return validate(root->left, subRoot, subRoot) || validate(root->right, subRoot, subRoot);
    }
};
