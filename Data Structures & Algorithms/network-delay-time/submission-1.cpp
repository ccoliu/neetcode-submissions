class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adjs(n + 1, vector<int>(n + 1, -1));

        for(auto t:times) {
            adjs[t[0]][t[1]] = t[2];
        }

        priority_queue<pair<int, int>> pq;
        vector<bool> visited(n + 1, false);
        vector<int> minlen(n + 1, INT_MAX);
        minlen[0] = -1;

        pq.push({0, k});
        int vi = 1;
        visited[k] = true;
        minlen[k] = 0;

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (val > minlen[idx]) continue;

            for(int i=0;i<=n;i++) {
                if (adjs[idx][i] != -1 && val + adjs[idx][i] < minlen[i]) {
                    if (!visited[i]) vi++;
                    visited[i] = true;
                    minlen[i] = val + adjs[idx][i];
                    pq.push({val + adjs[idx][i], i});
                }
            }
        }

        if (vi < n) return -1;
        return ranges::max(minlen);
    }
};
