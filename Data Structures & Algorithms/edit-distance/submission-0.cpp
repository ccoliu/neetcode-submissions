class Solution {
public:
    vector<vector<int>> dp;

    int dfs(string word1, string word2, int idx1, int idx2) {
        if (idx1 >= word1.length() && idx2 >= word2.length()) return 0;

        if (idx1 >= word1.length() && idx2 < word2.length()) return 1 + dfs(word1, word2, idx1, idx2 + 1);

        if (idx2 >= word2.length() && idx1 < word1.length()) return 1 + dfs(word1, word2, idx1 + 1, idx2);

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if (word1[idx1] == word2[idx2]) {
            return dp[idx1][idx2] = dfs(word1, word2, idx1 + 1, idx2 + 1);
        } 
        else {
            return dp[idx1][idx2] = 1 + min({dfs(word1, word2, idx1, idx2 + 1), dfs(word1, word2, idx1 + 1, idx2 + 1), dfs(word1, word2, idx1 + 1, idx2)});
        }
    }

    int minDistance(string word1, string word2) {
        int w1 = word1.length(), w2 = word2.length();
        dp.assign(w1 + 1, vector<int>(w2 + 1, -1));
        return dfs(word1, word2, 0, 0);
    }
};
