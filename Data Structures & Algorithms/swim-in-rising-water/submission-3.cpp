class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y, int n, int h, vector<vector<bool>>& v) {
        if (x == n - 1 && y == n - 1) {
            return true;
        }
        
        //if (grid[x][y] < h) return false;

        v[x][y] = true;

        if (x + 1 < n && grid[x + 1][y] <= h && !v[x+1][y]) {
            if (check(grid, x + 1, y, n, h, v)) return true;
        }

        if (y + 1 < n && grid[x][y + 1] <= h && !v[x][y+1]) {
            if (check(grid, x, y + 1, n, h, v)) return true;
        }

        if (x - 1 >= 0 && grid[x - 1][y] <= h && !v[x-1][y]) {
            if (check(grid, x - 1, y, n, h, v)) return true;
        }

        if (y - 1 >= 0 && grid[x][y - 1] <= h && !v[x][y-1]) {
            if (check(grid, x, y - 1, n, h, v)) return true;
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = grid[0][0], hi = n * n - 1;
        int ans = hi;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            visited[0][0] = true;

            if (check(grid, 0, 0, n, mid, visited)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
