class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int l, int r) {
        //select the last balloon to pop
        if (l >= r) {
            return 0;
        }

        if (dp[l][r] != 0) return dp[l][r];

        for(int i=l+1;i<r;i++) {
            int cur = nums[i] * nums[l] * nums[r];
            dp[l][r] = max(dp[l][r], cur + dfs(nums, l, i) + dfs(nums,i,r));
        }

        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int> num;
        num.push_back(1);
        num.insert(num.end(), nums.begin(), nums.end());
        num.push_back(1);

        int n = nums.size() + 2;
        dp.assign(n, vector<int>(n, 0));
        int l = 0, r = n - 1;
        return dfs(num, l, r);
    }
};
