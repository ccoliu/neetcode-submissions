class Solution {
public:
    vector<vector<int>> memo;
    bool dfs(string& s1, string& s2, string& s3, int i, int j, int& m, int& n, int& len) {
        if (i + j == len) return true;
        if (memo[i][j] != -1) return memo[i][j];

        int k = i + j;

        if (i < m && s1[i] == s3[k]) {
            if (dfs(s1, s2, s3, i+1, j, m, n, len)) {
                return memo[i][j] = 1;
            }
        }

        if (j < n && s2[j] == s3[k]) {
            if (dfs(s1, s2, s3, i, j+1, m, n, len)) {
                return memo[i][j] = 1;
            }
        }

        return memo[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        int len = s3.length();
        if (m + n != len) return false;
        memo.resize(m + 1, vector<int>(n + 1, -1));
        return dfs(s1, s2, s3, 0, 0, m, n, len);
    }
};
