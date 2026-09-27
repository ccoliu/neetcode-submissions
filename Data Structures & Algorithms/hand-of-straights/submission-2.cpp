class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(auto i: hand) mp[i]++;
        sort(hand.begin(), hand.end());

        for(int n: hand) {
            if (mp[n] > 0) {
                for(int i=n; i < n + groupSize; i++) {
                    if (--mp[i] < 0) return false;
                }
            }
        }

        return true;
    }
};
