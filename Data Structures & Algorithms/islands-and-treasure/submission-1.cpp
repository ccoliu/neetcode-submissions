class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>> q;
        int m = grid.size(), n = grid[0].size();

        for(int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto [val, pos] = q.front();
            q.pop();
            int x = pos.first, y = pos.second;
            if (val > grid[x][y]) continue;

            for(int i=0;i<4;i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1 && val < grid[nx][ny]) {
                    grid[nx][ny] = val + 1;
                    q.push({val + 1, {nx, ny}});
                }
            }
        }

        return;
    }
};
