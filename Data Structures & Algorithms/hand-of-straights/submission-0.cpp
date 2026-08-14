class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) return false;

        unordered_map<int,int> cards;
        set<int> nums;

        for(int i=0;i<n;i++) {
            cards[hand[i]]++;
            nums.insert(hand[i]);
        }

        int pairs = 0;
        while(pairs < (n / groupSize)) {
            int mini = -1;
            
            for(auto& key: nums) {
                if (cards[key] != 0) {
                    mini = key;
                    break;
                }
            }

            if (mini == -1) return false;
            else cards[mini]--;

            for(int i=1;i<groupSize;i++) {
                int need = mini + i;
                if (cards[need] != 0) {
                    cards[need]--;
                }
                else return false;
            }

            pairs++;
        }

        return true;
    }
};
