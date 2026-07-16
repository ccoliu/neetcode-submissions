class Solution {
public:
    vector<string> ans;
    void dfs(vector<string>& digi, string digits, string cur) {
        int n = cur.length();
        if (n == digits.length()) {
            ans.push_back(cur);
            return;
        }

        string cand = digi[digits[n] - '0'];
        for(int i=0;i<cand.length();i++) {
            cur += cand[i];
            dfs(digi, digits, cur);
            cur.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> digi = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digi, digits, "");
        return ans;
    }
};
