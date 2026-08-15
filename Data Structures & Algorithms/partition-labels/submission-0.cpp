class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        for(auto& c:s) {
            freq[c - 'a']++;
        }

        set<char> st;
        int idx = 0;
        int left = 0;
        vector<int> ans;

        while(idx < n) {
            int pt = s[idx] - 'a';
            freq[pt]--;
            if (st.find(pt) == st.end()) st.insert(s[idx]);
            if (freq[pt] == 0) st.erase(s[idx]);
            if (st.empty()) {
                ans.push_back(idx - left + 1);
                left = idx + 1;
            }
            idx++;
        }

        return ans;
    }
};
