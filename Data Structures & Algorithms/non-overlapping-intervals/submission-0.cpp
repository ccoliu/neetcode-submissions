class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; //照結束時間由小到大排序
        });

        int ans = 0;
        int last_finish = -1;
        int n = intervals.size();
        
        last_finish = intervals[0][1];
        for(int i=1;i<n;i++) {
            if (intervals[i][0] < last_finish) ans++;
            else {
                last_finish = intervals[i][1];
            }
        }

        return ans;
    }
};
