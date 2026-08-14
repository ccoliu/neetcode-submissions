class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int curfst = INT_MAX;
        int cursec = INT_MAX;
        int curtrd = INT_MAX;
        int n = triplets.size();

        for(auto t:triplets) {
            if (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                curfst = t[0];
                cursec = t[1];
                curtrd = t[2];
                break;
            }
        }

        if (curfst != target[0]) return false;

        if (cursec != target[1]) {
            for(auto t:triplets) {
                if (t[1] == target[1] && t[0] <= curfst && t[2] <= target[2]) {
                    cursec = t[1];
                    curtrd = t[2];
                    break;
                }
            }

            if (cursec != target[1]) return false;
        }

        if (curtrd != target[1]) {
            for(auto t:triplets) {
                if (t[2] == target[2] && t[0] <= curfst && t[1] <= cursec) {
                    curtrd = t[2];
                    break;
                }
            }

            if (curtrd != target[2]) return false;
        }

        return true;
    }
};
