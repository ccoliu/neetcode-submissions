class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited) {
        if (board[x][y] == 'X') return false;

        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return true;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        for(int i=0;i<4;i++) {
            int nx = x + dr[i], ny = y + dc[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (dfs(board, nx, ny, visited)) return true;
            }
        }

        return false;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (board[i][j] == 'O') {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if (dfs(board, i, j, visited) == false) {
                        board[i][j] = 'X';
                    }
                } 
            }
        }
    }
};
