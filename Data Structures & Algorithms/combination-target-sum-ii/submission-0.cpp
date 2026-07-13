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
        
        for(int i=idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }

            c.push_back(nums[i]);
            dfs(nums, target, cur + nums[i], i + 1, n, c);

            c.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> c;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, candidates.size(), c);
        return ans;
    }
};
