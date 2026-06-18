class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int l = 0, maxfreq = 0, res = 0;
        for(int r=0;r<s.length();r++) {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            // 視窗長度 - 最多字元數 > k，視窗不合法
            while((r - l + 1) - maxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
