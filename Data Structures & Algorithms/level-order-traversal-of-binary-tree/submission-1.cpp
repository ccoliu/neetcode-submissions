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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        int level = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        vector<int> vec;
        vector<vector<int>> ans;

        while(!q.empty()){
            auto [top, lv] = q.front();
            q.pop();
            if (lv > level) {
                ans.push_back(vec);
                level++;
                vec.clear();
            }

            vec.push_back(top->val);
            if (top->left) q.push({top->left, level + 1});
            if (top->right) q.push({top->right, level + 1});
        }

        if (!vec.empty()) ans.push_back(vec);
        return ans;
    }
};
