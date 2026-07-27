class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto w:words) {
            for(auto c: w) {
                if (indegree.find(c) == indegree.end()) {
                    indegree[c] = 0;
                }
            }
        }

        for(int i=0;i<words.size()-1;i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";
            }

            for(int j=0;j < min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) {
                    if (adj[s1[j]].find(s2[j]) == adj[s1[j]].end()) {
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        string ans = "";

        for(auto& [c, count]: indegree) {
            if (count == 0) q.push(c);
        }

        while(!q.empty()) {
            char c = q.front();
            q.pop();
            if (find(ans.begin(), ans.end(), c) == ans.end()) ans += c;

            auto s = adj[c];
            for (auto& sc: s) {
                indegree[sc]--;
                if (indegree[sc] == 0) {
                    q.push(sc);
                }
            }
        }

        return (ans.length() == indegree.size()) ? ans : "";
    }
};
