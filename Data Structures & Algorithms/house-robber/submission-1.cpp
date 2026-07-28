class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0; //dp[i-2]
        int rob2 = 0; //dp[i-1]

        //[rob1, rob2, n, n+1, ...]

        for (auto n:nums) {
            int cur = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = cur;
        }

        return rob2;
    }
};
