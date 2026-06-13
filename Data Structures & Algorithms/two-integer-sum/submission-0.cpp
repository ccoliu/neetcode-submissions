class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nmap;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int num = nums[i];
            if (nmap.find(target - num) != nmap.end()) {
                return {nmap[target - num], i};
            }
            nmap[num] = i;
        }
        return {-1, -1};
    }
};
