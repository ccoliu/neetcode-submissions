class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> box;
        for(auto n:nums) {
            if (box.count(n) >= 1) {
                return true;
            }
            box[n] = 1;
        }
        return false;
    }
};