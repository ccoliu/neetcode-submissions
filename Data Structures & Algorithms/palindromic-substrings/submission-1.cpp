class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        auto expand = [&](int left, int right) {
            int cnt = 0;
            while(left >= 0 && right < n && s[left] == s[right]) {
                cnt++;
                left--;
                right++;
            }

            return cnt;
        };

        for(int i=0;i<n;i++) {
            int odd = expand(i, i);
            int even = 0;

            if (i != n - 1) even = expand(i, i+1);

            ans += odd + even;
        }
        
        return ans;
    }
};
