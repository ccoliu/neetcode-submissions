class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX / 2);

        dp[n-1] = 0;

        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<i;j++) {
                if (nums[j] + j >= i) {
                    dp[j] = min(dp[j], 1 + dp[i]);
                }
            }
        }

        return dp[0];
    }
};
