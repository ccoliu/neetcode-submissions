class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tg = 0, tc = 0;
        for(int i=0;i<n;i++) {
            tg += gas[i];
            tc += cost[i];
        }

        if (tg < tc) return -1;

        int total = 0;
        int res = 0;

        for(int i=0;i<n;i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                res = i+1;
            }
        }
        return res;
    }
};
