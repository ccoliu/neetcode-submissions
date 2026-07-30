class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();

        int ans = n;

        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if (isPalindrome(s, i, j)) ans++;
            }
        }

        return ans;
    }
};
