class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.length()) {
            if (st.count(s[r])) {
                ans = max(ans, r - l);
                while(s[l] != s[r]) {
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
        }
        return max(ans, r - l);
    }
};
