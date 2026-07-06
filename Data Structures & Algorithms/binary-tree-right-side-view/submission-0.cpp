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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int cur = 0;

        while(!q.empty()) {
            auto [top, level] = q.front();
            q.pop();

            cout << top->val << " " << level << endl;

            if (level == cur) {
                ans.push_back(top->val);
                cur++;
            }

            if (top->right) q.push({top->right, level + 1});
            if (top->left) q.push({top->left, level + 1});
        }

        return ans;
    }
};
