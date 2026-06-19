class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        if (s == t) return s;

        unordered_map<char,int> mp;
        unordered_map<char,int> wd;
        for(auto c:t) {
            mp[c]++;
        }

        int have = 0, need = mp.size();
        int reslen = INT_MAX;
        int l = 0;
        pair<int,int> res = {-1, -1};

        for(int r=0;r<s.length();r++) {
            char c = s[r];
            wd[c]++;

            if (mp.count(c) && wd[c] == mp[c]) {
                have++;
            }

            while(have == need) {
                if ((r - l + 1) < reslen) {
                    reslen = r - l + 1;
                    res = {l, r};
                }
                
                wd[s[l]]--;

                if (mp.count(s[l]) && wd[s[l]] < mp[s[l]]) {
                    have--;
                }
                
                l++;
            }
        }

        return (reslen == INT_MAX) ? "" : s.substr(res.first, reslen);
    }
};
