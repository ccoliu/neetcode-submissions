class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(27, 0);
        for(auto t: tasks) {
            ++cnt[t - 'A'];
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++) {
            if (cnt[i] > 0) pq.push(cnt[i]);
        }

        queue<pair<int,int>> cd;
        int time = 0;

        while(!pq.empty() || !cd.empty()) {
            time++;

            if (!cd.empty() && cd.front().second == time) {
                pq.push(cd.front().first);
                cd.pop();
            }

            if (!pq.empty()) {
                int remain = pq.top() - 1;
                pq.pop();

                if (remain > 0) cd.push({remain, time + n + 1});
            }
        }

        return time;
    }
};
