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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()) {
            auto [top, value] = q.front();
            q.pop();
            if (top->val >= value && top != root) ans++;
            if (top->left) q.push({top->left, max(value, top->val)});
            if (top->right) q.push({top->right, max(value, top->val)});
        }

        return ans;
    }
};
