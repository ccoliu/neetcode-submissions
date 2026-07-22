class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjs(n);
        vector<int> degree(n, 0);

        vector<int> ans;

        for(auto p: prerequisites) {
            adjs[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int c = q.front();
            q.pop();
            ans.push_back(c);

            for(int nxt: adjs[c]) {
                degree[nxt]--;
                if (degree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        return (ans.size() == n) ? ans : vector<int>{};
    }
};
