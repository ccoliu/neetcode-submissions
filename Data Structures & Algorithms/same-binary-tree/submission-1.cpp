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
    bool solve(TreeNode* nodep, TreeNode* nodeq) {
        if (!nodep && !nodeq) return true;
        else if (!nodep || !nodeq) return false;

        if (nodep->val != nodeq->val) return false;

        return solve(nodep->left, nodeq->left) && solve(nodep->right, nodeq->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        
        if (p->val != q->val) return false;
        return solve(p->left, q->left) && solve(p->right, q->right);
    }
};
