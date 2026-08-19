class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); 
        int q = queries.size();
        
        vector<pair<int,int>> sortedq(q);
        vector<int> ans(q, -1);

        for(int i=0;i<q;i++) {
            sortedq[i] = {queries[i], i};
        }

        sort(sortedq.begin(), sortedq.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int i = 0;
        int n = intervals.size();

        for(auto& sq: sortedq) {
            int qu = sq.first;
            int orig = sq.second;

            while(i < n && intervals[i][0] <= qu) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while(!pq.empty() && pq.top().second < qu) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[orig] = pq.top().first;
            }
        }
        return ans;
    }
};
