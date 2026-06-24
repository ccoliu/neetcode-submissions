class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int total_time = 0;

            for(auto p: piles) {
                if (p % mid == 0) {
                    total_time += (p / mid);
                }
                else total_time += (p / mid) + 1;
            }

            if (total_time <= h) {
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return l;
    }
};
