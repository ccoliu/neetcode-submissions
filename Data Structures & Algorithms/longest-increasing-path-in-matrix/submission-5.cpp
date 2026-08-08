class Solution {
public:
    vector<vector<int>> memo;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& matrix, int& m, int &n, int x, int y) {
        if (memo[x][y] != -1) return memo[x][y];
        int mx = 1;
        for(int i=0;i<4;i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                mx = max(mx, 1 + dfs(matrix, m, n, nx, ny));
            }
        }
        return memo[x][y] = mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        memo.resize(m, vector<int>(n, -1));
        int mx = 1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mx = max(mx, dfs(matrix, m, n, i, j));
            }
        }

        return mx;
    }
};
