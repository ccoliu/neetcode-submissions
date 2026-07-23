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
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu dsu(n);
        for(auto e:edges) {
            dsu.Union(e[0], e[1]);
        }

        for(int i=0;i<n;i++) {
            dsu.find(i);
        }

        unordered_set<int> st(dsu.parents.begin(), dsu.parents.end());
        return st.size();
    }
};
