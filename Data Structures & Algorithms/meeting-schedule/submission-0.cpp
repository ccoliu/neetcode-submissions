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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        int n = intervals.size();
        int last_finish = intervals[0].end;
        
        for(int i=1;i<n;i++) {
            if (intervals[i].start < last_finish) {
                return false;
            }
            else {
                last_finish = intervals[i].end;
            }
        }

        return true;
    }
};
