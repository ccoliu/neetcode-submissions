class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) return false;

        map<int,int> cards;

        for(int i=0;i<n;i++) {
            cards[hand[i]]++;
        }

        int pairs = 0;
        while(pairs < (n / groupSize)) {
            if (cards.size() == 0) return false;
            int mini = cards.begin()->first;

            cards[mini]--;

            if (cards[mini] == 0) cards.erase(mini);

            for(int i=1;i<groupSize;i++) {
                int need = mini + i;
                if (cards[need] != 0) {
                    cards[need]--;
                    if (cards[need] == 0) cards.erase(need);
                }
                else return false;
            }

            pairs++;
        }

        return true;
    }
};
