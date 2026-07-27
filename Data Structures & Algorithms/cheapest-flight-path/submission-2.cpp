class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adjs(n, vector<int>(n, -1));
        vector<int> cost(n, INT_MAX);

        for(auto f: flights) {
            adjs[f[0]][f[1]] = f[2];
        }

        using state = tuple<int, int, int>;
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({0, 0, src});

        while(!pq.empty()) {
            auto [cst, tk, pos] = pq.top();
            pq.pop();
            if (pos == dst) return cst;
            if (tk > k) continue;

            for(int i=0;i<n;i++) {
                if (adjs[pos][i] != -1 && i == dst && tk <= k && cst + adjs[pos][i] < cost[i]) {
                    cost[i] = cst + adjs[pos][i];
                    pq.push({cost[i], tk, i});
                }
                else if (adjs[pos][i] != -1 && i != dst && tk + 1 <= k && cst + adjs[pos][i] < cost[i]) {
                    cost[i] = cst + adjs[pos][i];
                    pq.push({cost[i], tk + 1, i});
                }
            }
        }

        return -1;
    }
};
