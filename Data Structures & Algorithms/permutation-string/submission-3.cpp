class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(auto c: s1) {
            freq[c - 'a']++;
        }

        int l=0, r=0;
        vector<int> temp = freq;
        while(r < s2.length()) {
            if (temp[s2[r] - 'a'] > 0) {
                temp[s2[r] - 'a']--;
            }
            else if (s2[l] == s2[r]) {
                l++;
            }
            else {
                temp = freq;
                l = r + 1;
            }

            cout << l << " " << r << endl;
            if ((r - l + 1) == s1.length()) {
                return true;
            }
            r++;
        }
        return false;
    }
};
