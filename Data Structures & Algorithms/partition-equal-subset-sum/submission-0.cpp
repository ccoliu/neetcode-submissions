class Solution {
public:
    bool dfs(int& sum, vector<int>& nums,int idx, int n, int cur) {
        if (cur == sum / 2) {
            return true;
        }

        if (idx == n) return false;

        cur += nums[idx];
        if (dfs(sum, nums, idx + 1, n, cur)) return true;

        cur -= nums[idx];
        if (dfs(sum, nums, idx + 1, n, cur)) return true;

        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;

        int n = nums.size();

        return dfs(sum, nums, 0, n, 0);
    }
};
