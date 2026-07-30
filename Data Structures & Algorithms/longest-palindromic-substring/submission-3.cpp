class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.length();

        int start = 0;
        int maxlen = 0;

        auto expand = [&](int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1;
        };

        for(int i=0;i<n;i++) {
            int odd = expand(i,i);
            int even = 0;

            if (i != n - 1) even = expand(i, i + 1);

            int len = max(odd, even);

            if (len > maxlen) {
                maxlen = len;
                start = i - floor((len - 1) / 2);
            }
        }

        return s.substr(start, maxlen);
    }
};
