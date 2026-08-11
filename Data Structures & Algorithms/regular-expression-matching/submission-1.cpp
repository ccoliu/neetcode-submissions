class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(string& s, string& p, int& n1, int& n2, int si, int pi) {
        if (pi == n2) return si == n1;

        if (dp[si][pi] != -1) return dp[si][pi] == 1;

        bool first_match = (si < n1 && (p[pi] == '.' || s[si] == p[pi]));

        bool ans = false;

        if (pi + 1 < n2 && p[pi + 1] == '*') {
            ans = dfs(s, p, n1, n2, si, pi + 2) || (first_match && dfs(s, p, n1, n2, si + 1, pi));
        }
        else if (first_match) {
            ans = dfs(s, p, n1, n2, si + 1, pi + 1);
        }

        return (dp[si][pi] = ans);
    }

    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        int si = 0, pi = 0;
        
        dp.assign(n1 + 1, vector<int>(n2 + 1, -1));

        return dfs(s, p, n1, n2, si, pi);
    }
};
