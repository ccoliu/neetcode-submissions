class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int cur, int n, vector<int>& c) {
        ans.push_back(c);

        for(int i=cur;i<n;i++) {
            if (i > cur && nums[i] == nums[i-1]) {
                continue;
            }
            
            c.push_back(nums[i]);
            dfs(nums, i + 1, n, c);
            c.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> c;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, nums.size(), c);
        return ans;
    }
};
