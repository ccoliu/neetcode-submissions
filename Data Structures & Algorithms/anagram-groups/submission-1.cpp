class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto s:strs) {
            vector<int> freq(26, 0);
            for(char c: s) {
                freq[c - 'a']++;
            }
            string key = "";
            for(int i=0;i<26;i++) {
                key += '#' + freq[i];
            }
            mp[key].push_back(s);
        }
        for(auto [s, lst]: mp) {
            ans.push_back(lst);
        }
        return ans;
    }
};
