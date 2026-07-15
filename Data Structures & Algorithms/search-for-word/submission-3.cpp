class Solution {
public:
    int m, n, len;
    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int idx) {
        if (idx >= len) return false;
        if (idx == len - 1) return true;
        char temp;

        if (x - 1 >= 0 && board[x - 1][y] == word[idx + 1]) {
            temp = board[x - 1][y];
            board[x - 1][y] = '#';
            if (dfs(board, x - 1, y, word, idx + 1)) return true;
            board[x - 1][y] = temp;
        }

        if (x + 1 < m && board[x + 1][y] == word[idx + 1]) {
            temp = board[x + 1][y];
            board[x + 1][y] = '#';
            if (dfs(board, x + 1, y, word, idx + 1)) return true;
            board[x + 1][y] = temp;
        }

        if (y - 1 >= 0 && board[x][y - 1] == word[idx + 1]) {
            temp = board[x][y - 1];
            board[x][y - 1] = '#';
            if (dfs(board, x, y - 1, word, idx + 1)) return true;
            board[x][y - 1] = temp;
        }

        if (y + 1 < n && board[x][y + 1] == word[idx + 1]) {
            temp = board[x][y + 1];
            board[x][y + 1] = '#';
            if (dfs(board, x, y + 1, word, idx + 1)) return true;
            board[x][y + 1] = temp;
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
                    char temp = board[i][j];
                    board[i][j] = '#';
                    if (dfs(board, i, j, word, 0)) return true;
                    board[i][j] = temp;
                }
            }
        }

        return false;
    }
};
