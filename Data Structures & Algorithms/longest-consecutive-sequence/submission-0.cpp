class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto n:nums) {
            if (st.count(n - 1)) continue;
            else {
                int temp = n, cur = 0;
                while(st.count(temp++)) cur++;
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
