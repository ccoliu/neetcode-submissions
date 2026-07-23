class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        queue<pair<int, string>> q;

        int n = wordList.size();
        int len = beginWord.length();
        vector<bool> visited(n, false);

        q.push({1, beginWord});

        while(!q.empty()) {
            auto [val, s] = q.front();
            q.pop();
            if (s == endWord) return val;

            for(int i=0;i<n;i++) {
                int cmp = 0;
                for(int j=0;j<len;j++) {
                    if (s[j] != wordList[i][j]) cmp++;
                }

                if (cmp == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push({val + 1, wordList[i]});
                }
            }
        }

        return 0;
    }
};
