class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int mx = nums[0], mi = nums[0];
        int ans = INT_MIN;

        for(int i=1;i<n;i++) {
            int tmp = mx;
            mx = max({mi * nums[i], mx * nums[i], nums[i]});
            mi = min({mi * nums[i], tmp * nums[i], nums[i]});
            ans = max({ans, mx, mi});
        }

        return ans;
    }
};
