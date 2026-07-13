class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int& target, int cur, int idx, int n, vector<int>& c) {
        if (cur == target) {
            ans.push_back(c);
            return;
        }
        else if (cur > target || idx >= n) {
            return;
        }
        
        dfs(nums, target, cur, idx + 1, n, c);

        cur += nums[idx];
        c.push_back(nums[idx]);

        dfs(nums, target, cur, idx, n, c);

        c.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> c;
        dfs(nums, target, 0, 0, nums.size(), c);
        return ans;
    }
};
