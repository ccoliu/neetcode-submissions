class Solution {
public:
    class dsu {
        public:
        vector<int> parents;

        dsu(int n) {
            parents.resize(n);
            iota(parents.begin(), parents.end(), 0);
        }

        int find(int x) {
            if (parents[x] == x) return x;
            else return parents[x] = find(parents[x]);
        }

        void Union(int x, int y) {
            int rx = find(x), ry = find(y);

            if (rx != ry) {
                parents[ry] = rx;
            }

            return;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu dsu(101);
        for(auto e:edges) {
            if (dsu.find(e[0]) == dsu.find(e[1])) {
                return {e[0], e[1]};
            }

            dsu.Union(e[0], e[1]);
        }

        return {-1, -1};
    }
};
