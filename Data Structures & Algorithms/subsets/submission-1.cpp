class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int> cur, int idx) {
        if (idx < n) {
            dfs(nums, n, cur, idx + 1);

            cur.push_back(nums[idx]);
            dfs(nums, n, cur, idx + 1);
        }
        else {
            ans.push_back(cur);
            return;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, nums.size(), {}, 0);
        return ans;    
    }
};
