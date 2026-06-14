class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        int n = nums.size();
        int mult = 1;
        for(auto num:nums) {
            if (num == 0) {
                zeros++;
                continue;
            }
            mult *= num;
        }
        vector<int> ans(n, 0);
        if (zeros >= 2) return ans;
        for(int i=0;i<n;i++) {
            if (zeros == 1 && nums[i] != 0) {
                continue;
            }
            else if (zeros == 1 && nums[i] == 0) {
                ans[i] = mult;
            }
            else {
                ans[i] = mult / nums[i];
            }
        }
        return ans;
    }
};
