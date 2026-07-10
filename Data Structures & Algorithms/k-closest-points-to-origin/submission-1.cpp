class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b) {
            return sqrt(a.first * a.first + a.second * a.second) < sqrt(b.first * b.first + b.second * b.second);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto p:points) {
            pq.push({p[0], p[1]});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto [x, y] = pq.top();
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};
