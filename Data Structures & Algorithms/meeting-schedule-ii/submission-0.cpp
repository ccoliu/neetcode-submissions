/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;

        for(auto i:intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end()); //0, 5, 15
        sort(end.begin(), end.end()); //10, 20, 40

        int cnt = 0;
        int s = 0;
        int e = 0;
        while(s < n && e < n) {
            if (start[s] < end[e]) {
                cnt++;
                s++;
            }
            else {
                s++;
                e++;
            }
        }

        return cnt;
    }
};
