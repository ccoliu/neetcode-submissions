class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int>& cur, int idx) {
        if (idx < n) {
            dfs(nums, n, cur, idx + 1);

            cur.push_back(nums[idx]);
            dfs(nums, n, cur, idx + 1);

            cur.pop_back();
        }
        else {
            ans.push_back(cur);
            return;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, nums.size(), cur, 0);
        return ans;    
    }
};
