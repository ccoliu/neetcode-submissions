class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int mx = nums[0], mi = nums[0];
        int ans = INT_MIN;

        for(int i=1;i<n;i++) {
            if (nums[i] < 0) {
                swap(mx, mi);
            }

            mx = max(nums[i], mx * nums[i]);
            mi = min(nums[i], mi * nums[i]);

            ans = max(mx, ans);
        }

        return ans;
    }
};
