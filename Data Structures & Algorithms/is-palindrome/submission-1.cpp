class Solution {
public:
    string formatted(string s) {
        for(int i=0;i<s.length();i++) {
            if (s[i] - 'a' < 26 && s[i] - 'a' >= 0 || s[i] - '0' < 10 && s[i] - '0' >= 0) {
                continue;
            }
            else if (s[i] - 'A' < 26 && s[i] - 'A' >= 0) {
                s[i] = 'a' + (s[i] - 'A');
            }
            else {
                s.erase(s.begin() + i);
                i--;
            }
        }
        return s;
    }
    bool isPalindrome(string s) {
       s = formatted(s);
       string temp = s;
       reverse(s.begin(), s.end());
       return temp == s;
    }
};
