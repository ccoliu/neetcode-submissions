class Solution {
public:
    int m,n;
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<int>>& visited) {
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            for(int i=0;i<4;i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && heights[x][y] <= heights[nx][ny] && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        vector<vector<int>> p_visited(m, vector<int>(n, 0));
        vector<vector<int>> a_visited(m, vector<int>(n, 0));

        queue<pair<int,int>> p;
        for(int i=0;i<m;i++) {
            p.push({i, 0});
            p_visited[i][0] = 1;
        }

        for(int i=0;i<n;i++) {
            p.push({0, i});
            p_visited[0][i] = 1;
        }


        bfs(heights, p, p_visited);

        queue<pair<int,int>> a;

        for(int i=0;i<m;i++) {
            a.push({i, n-1});
            a_visited[i][n-1] = 1;
        }

        for(int i=0;i<n;i++) {
            a.push({m-1, i});
            a_visited[m-1][i] = 1;
        }

        bfs(heights, a, a_visited);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (p_visited[i][j] == 1 && a_visited[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
