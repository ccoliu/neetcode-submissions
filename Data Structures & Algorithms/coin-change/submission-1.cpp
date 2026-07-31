class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        queue<pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [m, times] = q.front();
            q.pop();
            if (m > amount) break;

            for(int i=0;i<n;i++) {
                long long cur = 1LL * m + coins[i];

                if (cur <= amount && times + 1 < dp[cur]) {
                    dp[cur] = times + 1;
                    q.push({cur, times + 1});
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
