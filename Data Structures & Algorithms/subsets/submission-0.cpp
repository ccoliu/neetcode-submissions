class Solution {
public:
    set<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int> cur, int idx) {
        ans.insert(cur);

        if (idx < n) {
            dfs(nums, n, cur, idx + 1);

            cur.push_back(nums[idx]);
            dfs(nums, n, cur, idx + 1);
        }

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, nums.size(), {}, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;    
    }
};
