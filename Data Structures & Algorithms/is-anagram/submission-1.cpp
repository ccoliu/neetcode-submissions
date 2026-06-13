class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<int,int> box;
        for(auto n:s) {
            box[n]++;
        }
        for(auto n:t) {
            if (box.count(n) >= 1) {
                box[n]--;
                if (box[n] == 0) {
                    box.erase(n);
                }
            }
        }
        return box.empty();
    }
};
