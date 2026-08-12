class Solution {
public:
    //dp + memo
    vector<int> dp; //只需一維dp

    bool jump(vector<int>& nums, int idx, int n) {
        if (idx >= n-1) return true;

        if (dp[idx] == 0) return false;

        if (dp[idx] != -1) return dp[idx] == 1;

        bool canjump = false;

        for(int i=nums[idx];i>0;i--) {
            canjump = canjump || jump(nums, idx + i, n);
        }

        return dp[idx] = canjump;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return jump(nums, 0, n);
    }
};
