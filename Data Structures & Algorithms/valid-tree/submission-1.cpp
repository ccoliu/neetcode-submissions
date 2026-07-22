class Solution {
public:
    bool cycle(int n, vector<vector<int>>& adjs, vector<int>& visited, int node, int parent) {
        visited[node] = 1;
        for(int i=0;i<n;i++) {
            if (adjs[node][i] == 1 && i != parent) {
                if (visited[i] == 2) continue;
                if (visited[i] == 1) return true;
                else {
                    if (cycle(n, adjs, visited, i, node)) return true;
                    visited[i] = 2;
                }
            }
        }
        visited[node] = 2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n, vector<int>(n, 0));
        vector<int> visited(n, 0);
        int egs = 0;

        for(auto e: edges) {
            adjs[e[0]][e[1]] = 1;
            adjs[e[1]][e[0]] = 1;
            egs++;
        }

        if (egs != n - 1) return false;

        for(int i=0;i<n;i++) {
            if (visited[i] == 2) continue;

            visited[i] = 1;
            if (cycle(n, adjs, visited, i, -1)) return false;
            visited[i] = 2;
        }

        return true;
    }
};
