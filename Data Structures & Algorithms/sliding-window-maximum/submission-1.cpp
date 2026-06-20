class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> dq;
        int l=0, r=0;

        while(r < n) {
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if (l > dq.front()) {
                dq.pop_front();
            }

            if (r + 1 >= k) {
                ans[l] = nums[dq.front()];
                l++;
            }

            r++;
        }

        return ans;
    }
};
