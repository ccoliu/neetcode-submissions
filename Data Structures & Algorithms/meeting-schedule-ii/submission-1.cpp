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
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> rooms;
        int n = intervals.size();

        for(int i=0;i<n;i++) {
            if (rooms.empty()) rooms.push(intervals[i].end);
            else {
                auto end = rooms.top();
                if (end > intervals[i].start) {
                    rooms.push(intervals[i].end);
                }
                else { // the least ending room is <= new interval, release and register the room
                    rooms.pop();
                    rooms.push(intervals[i].end);
                }
            }
        }

        return rooms.size();
    }
};
