class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjs(n);
        vector<int> degree(n, 0);
        int valid = 0;

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
            valid++;

            for(int nxt: adjs[c]) {
                degree[nxt]--;
                if (degree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        return valid == n;
    }
};
