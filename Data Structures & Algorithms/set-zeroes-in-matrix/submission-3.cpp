class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<int,int>> pos;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (matrix[i][j] == 0) {
                    pos.push_back({i, j});
                }
            }
        }

        for(auto& p:pos) {
            int row = p.second;
            int col = p.first;

            for(int i=0;i<n;i++) {
                matrix[col][i] = 0;
            }

            for(int i=0;i<m;i++) {
                matrix[i][row] = 0;
            }
        }
    }
};
