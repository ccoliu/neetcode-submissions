class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        int rob1 = 0; //dp[i-2]
        int rob2 = 0; //dp[i-1]

        //[rob1, rob2, n, n+1, ...]

        for (int i = start; i <= end; i++) {
            int cur = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = cur;
        }

        return rob2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(rob1(nums, 0, n-2), rob1(nums, 1, n-1));
    }
};
