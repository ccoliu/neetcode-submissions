class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)  {
        bool match1 = false, match2 = false, match3 = false;

        for(const auto& t: triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            match1 = match1 || (t[0] == target[0]);
            match2 = match2 || (t[1] == target[1]);
            match3 = match3 || (t[2] == target[2]);
        }

        return match1 && match2 && match3;
    }
};
