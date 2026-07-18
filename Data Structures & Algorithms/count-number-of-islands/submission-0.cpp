class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& island, int x, int y, int idx) {
        if (island[x][y] != 0) return;
        island[x][y] = idx;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        for(int i=0;i<4;i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && island[nx][ny] == 0) {
                dfs(grid, island, nx, ny, idx);
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> island(n, vector<int>(m, 0));
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                }
            }
        }


        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (island[x][y] != 0) continue;
            ans++;
            dfs(grid, island, x, y, ans);
        }

        return ans;
    }
};
