class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int mx_reach = 0;
        int ans = 0;
        
        for(int i=0;i<n-1;i++) {
            mx_reach = max(mx_reach, i + nums[i]);

            if (i == cur) {
                ans++;
                cur = mx_reach;
            }

            if (cur == n - 1) break;
        }

        return ans;
    }
};
