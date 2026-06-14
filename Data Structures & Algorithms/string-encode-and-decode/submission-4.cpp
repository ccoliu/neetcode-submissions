class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "&empty&";
        }
        string ans = "";
        for(auto s:strs) {
            ans += s + "&spc&";
        }
        return ans.substr(0, ans.length() - 5);
    }

    vector<string> decode(string s) {
        if (s == "&empty&") return {};
        vector<string> ans;
        for(int i=0;i<s.length();i++) {
            if (s.substr(i, 5) == "&spc&") {
                string last = s.substr(i+5);
                string first = s.substr(0, i);
                ans.push_back(first);
                s = last;
                i = 0;
            }
        }
        ans.push_back(s);
        return ans;
    }
};
