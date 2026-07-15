class Solution {
public:
    vector<string> ans;
    void dfs(int n, string& str, int left, int right) {
        if (right > left) return;
        if (left + right > n * 2) return;
        if (left + right == n * 2 && left == right) {
            ans.push_back(str);
            return;
        }

        str += '(';
        dfs(n, str, left + 1, right);
        str.pop_back();

        str += ')';
        dfs(n, str, left, right + 1);
        str.pop_back();
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        dfs(n, str, 0, 0);
        return ans;
    }
};
