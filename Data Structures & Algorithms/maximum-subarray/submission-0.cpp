class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int cur = 0;
        for(int i=0;i<n;i++) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(ans, cur);
        }

        return ans;
    }
};
