class Solution {
public:
    //key: find value in sorted subarray
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[l] <= nums[mid]) { //left is sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            else { // right is sorted
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }

        return -1;
    }
};
