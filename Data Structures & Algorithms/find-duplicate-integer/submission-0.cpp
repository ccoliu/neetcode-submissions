class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int rabbit = 0, turtle = 0;

        while(true) {
            rabbit = nums[nums[rabbit]];
            turtle = nums[turtle];
            if (rabbit == turtle) break;
        }

        turtle = 0;
        while(turtle != rabbit) {
            turtle = nums[turtle];
            rabbit = nums[rabbit];
        }

        return turtle;
    }
};
