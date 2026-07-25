class Solution {
public:
    class dsu {
        public:
            vector<int> parent;

            dsu(int n) {
                parent.resize(n);
                iota(parent.begin(), parent.end(), 0);
            }

            int find(int x) {
                if (parent[x] == x) return x;
                else return parent[x] = find(parent[x]);
            }

            void Union(int x, int y) {
                int rx = find(x), ry = find(y);
                if (rx != ry) {
                    parent[ry] = rx;
                }
                return;
            }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        dsu dsu(n);

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dis, {i, j}});
            }
        }

        int connected = 1;
        int cost = 0;
        while(!pq.empty()) {
            auto [val, pos] = pq.top();
            int e1 = pos.first, e2 = pos.second;
            pq.pop();

            if (connected == n) break;
            if (dsu.find(e1) == dsu.find(e2)) continue;

            cost += val;
            connected++;
            dsu.Union(e1, e2);
        }

        return cost;
    }
};
