class Solution {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++) {
            bool allocated = false;
            for(int j=0;j<ans.size();j++) {
                string cand = ans[j][0];
                if (isAnagram(cand, strs[i])) {
                    ans[j].push_back(strs[i]);
                    allocated = true;
                    break;
                }
            }

            if (!allocated) {
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};
