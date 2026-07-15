class Solution {
public:
    int n;
    vector<vector<string>> ans;

    bool isPalindrome(const string& s, int left, int right) {
        while(left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void dfs(string& s, int start, vector<string>& cur) {
        if (start == n) {
            ans.push_back(cur);
            return;
        }

        for(int i=start;i<n;i++) {
            if (isPalindrome(s, start, i)) { //先判斷當前substr是否palindrome
                cur.push_back(s.substr(start, i - start + 1));

                dfs(s, i + 1, cur);

                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> path;
        dfs(s, 0, path);
        return ans;
    }
};
