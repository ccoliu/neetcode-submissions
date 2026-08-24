class CountSquares {
public:
    int cnt[1001][1001] = {0};
    vector<pair<int,int>> pts;

    CountSquares() {
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
        pts.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int qx = point[0], qy = point[1];
        for(auto [x, y]: pts) {
            if (x != qx && y != qy && abs(qx - x) == abs(qy - y)) {
                ans += (cnt[qx][y] * cnt[x][qy]);
            }
        }
        return ans;
    }
};
