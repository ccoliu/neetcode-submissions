class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int half = floor(n);

        string left = s.substr(0, half);
        reverse(s.begin(), s.end());
        string right = s.substr(0, half);

        return left == right;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n - 1;

        string ans = "";

        ans += s[0];

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub)) {
                    if (sub.length() > ans.length()) {
                        ans = sub;
                    }
                }
            }
        }

        return ans;
    }
};
