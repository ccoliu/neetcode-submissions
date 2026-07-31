class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(const auto& w: wordDict) {
                if ((i + w.length()) <= n && s.substr(i, w.length()) == w) {
                    dp[i] = dp[i + w.length()];
                }
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};
