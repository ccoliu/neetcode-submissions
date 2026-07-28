class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);

        for(int i=1;i<=n;i++) {
            if (i >= 2) {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            }
            else dp[i] = max(nums[i-1], dp[i-1]);
        }

        return dp[n];
    }
};
