class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        int ans = 0;
        queue<pair<int, pair<int,int>>> q;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto [val, pos] = q.front();
            int x = pos.first, y = pos.second;
            ans = max(ans, val);
            q.pop();

            for(int i=0;i<4;i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    fresh--;
                    grid[nx][ny] = 2;
                    q.push({val + 1, {nx, ny}});
                }
            }
        }

        return (fresh == 0) ? ans : -1;
    }
};
