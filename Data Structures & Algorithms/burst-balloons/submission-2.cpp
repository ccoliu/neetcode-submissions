class Solution {
public:
    vector<vector<int>> dp;

    int burst(vector<int>& total, int left, int right) {
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];

        int ans = 0;

        for(int i = left + 1; i < right; i++) {
            ans = max(ans, burst(total, left, i) + burst(total, i, right) + total[left] * total[i] * total[right]);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> total;
        total.push_back(1);
        total.insert(total.end(), nums.begin(), nums.end());
        total.push_back(1);

        int n = total.size();
        dp.assign(n, vector<int>(n, -1));

        int left = 0, right = n - 1;

        return burst(total, left, right);
    }
};
