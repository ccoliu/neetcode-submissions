class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int>& c) {
        if (c.size() == n) {
            ans.push_back(c);
            return;
        }
        if (c.size() > n) return;

        for(int i=0;i<n;i++) {
            if (c.empty()) {
                c.push_back(nums[i]);
                dfs(nums, n, c);
                c.pop_back();
            }
            else if (find(c.begin(), c.end(), nums[i]) == c.end()) {
                c.push_back(nums[i]);
                dfs(nums, n, c);
                c.pop_back();
            }
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> c;
        dfs(nums, nums.size(), c);
        return ans;
    }
};
