class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int ans = 1;
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        for(int i=0;i<4;i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                ans += dfs(grid, visited, nx, ny); 
            }
        }

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = 1;
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
};
