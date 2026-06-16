class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n):
            if nums[i] > 0:
                break
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            small = i + 1
            big = n - 1
            while small < big:
                res = nums[i] + nums[small] + nums[big]
                if res == 0:
                    ans.append([nums[i], nums[small], nums[big]])
                    while small + 1 < big and nums[small + 1] == nums[small]:
                        small += 1
                    while big - 1 > small and nums[big - 1] == nums[big]:
                        big -= 1
                    small += 1
                    big -= 1
                elif res > 0:
                    big -= 1
                else:
                    small += 1
        return ans
            
        