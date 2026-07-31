class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if (i == 0) return true;

            if (i < 0) return false;

            if (dp[i] != -1) return dp[i];

            for(int j = i-1 ; j >= 0;j--) {
                if (words.contains(s.substr(j, i-j)) && dfs(j)) {
                    return dp[i] = true;
                }
            }

            return dp[i] = false;
        };

        return dfs(n);
    }
};
