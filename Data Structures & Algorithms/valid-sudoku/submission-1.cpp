class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> bd(9, vector<int>(9, 0));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (board[i][j] == '.') continue;
                bd[i][j] = board[i][j] - '0';
            }
        }

        for(int i=0;i<9;i++) {
            vector<int> arr(10, 1);
            for(int j=0;j<9;j++) {
                if (bd[i][j] != 0 && --arr[bd[i][j]] < 0) {
                    cout << i << " " << j << " " << bd[i][j] << endl;
                    cout << "row" << endl;
                    return false;
                } 
            }
        }

        for(int i=0;i<9;i++) {
            vector<int> arr(10, 1);
            for(int j=0;j<9;j++) {
                if (bd[j][i] != 0 && --arr[bd[j][i]] < 0) {
                    cout << "col" << endl;
                    return false;
                } 
            }
        }

        for(int i=0;i<9;i++) {
            vector<int> arr(10, 1);
            for(int j=0;j<9;j++) {
                int row = (i / 3) * 3 + j / 3;
                int col = (i % 3) * 3 + j % 3;
                if (bd[row][col] != 0 && --arr[bd[row][col]] < 0) {
                    cout << "block" << endl;
                    return false;
                }
            }
        }

        return true;
    }
};
