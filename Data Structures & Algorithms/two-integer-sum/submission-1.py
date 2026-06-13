class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dt = {}
        n = len(nums)
        for i in range(n):
            num = nums[i]
            if (target - num) in dt:
                return [dt[target - num], i]
            dt[num] = i
        return [-1, -1]
