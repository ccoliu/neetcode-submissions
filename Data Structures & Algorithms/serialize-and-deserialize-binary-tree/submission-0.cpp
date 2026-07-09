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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        auto dfs = [&](auto& self, TreeNode* node) -> void {
            if (!node) {
                ans += "N,";
                return;
            }

            ans += to_string(node->val) + ",";
            self(self, node->left);
            self(self, node->right);
        };

        dfs(dfs, root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        int len = 0;

        auto dfs = [&](auto& self) -> TreeNode* {
            if (len >= data.length()) return nullptr;
            
            int next_comma = data.find(',', len);
            string val_str = data.substr(len, next_comma - len);
            len = next_comma + 1;

            if (val_str == "N") return nullptr;
            TreeNode* node = new TreeNode(stoi(val_str));
            
            node->left = self(self);
            node->right = self(self);

            return node;
        };

        return dfs(dfs);
    }
};
