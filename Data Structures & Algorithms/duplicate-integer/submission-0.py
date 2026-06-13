class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        box = {}
        for n in nums:
            if box.get(n) != None:
                return True
            box[n] = 1
        return False