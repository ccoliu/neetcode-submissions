class Solution {
public:
    vector<vector<string>> ans;
    bool valid(vector<pair<int,int>>& pos, int x, int y) {
        for(auto& [px, py]: pos) {
            if (px == x || py == y) return false;
            if (abs(px - x) == abs(py - y)) return false;
        }
        return true;
    }
    void dfs(vector<string>& board, vector<pair<int,int>>& pos, int q, int n) {
        if (q == n) {
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++) {
            if (!valid(pos, q, j)) continue;

            board[q][j] = 'Q';
            pos.push_back({q, j});
            dfs(board, pos, q + 1, n);
            
            board[q][j] = '.';
            pos.pop_back();
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<pair<int,int>> pos;
        dfs(board, pos, 0, n);
        return ans;
    }
};
