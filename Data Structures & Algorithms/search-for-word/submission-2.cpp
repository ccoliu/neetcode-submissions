class Solution {
public:
    int m, n, len;
    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string& word, int idx) {
        if (idx >= len) return false;
        if (idx == len - 1) return true;

        if (x - 1 >= 0 && board[x - 1][y] == word[idx + 1] && !visited[x - 1][y]) {
            visited[x - 1][y] = true;
            if (dfs(board, x - 1, y, visited, word, idx + 1)) return true;
            visited[x - 1][y] = false;
        }

        if (x + 1 < m && board[x + 1][y] == word[idx + 1] && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            if (dfs(board, x + 1, y, visited, word, idx + 1)) return true;
            visited[x + 1][y] = false;
        }

        if (y - 1 >= 0 && board[x][y - 1] == word[idx + 1] && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            if (dfs(board, x, y - 1, visited, word, idx + 1)) return true;
            visited[x][y - 1] = false;
        }

        if (y + 1 < n && board[x][y + 1] == word[idx + 1] && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            if (dfs(board, x, y + 1, visited, word, idx + 1)) return true;
            visited[x][y + 1] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        len = word.length();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (word[0] == board[i][j]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if (dfs(board, i, j, visited, word, 0)) return true;
                }
            }
        }

        return false;
    }
};
