class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dt = defaultdict(list)
        for i in range(len(numbers)):
            if target - numbers[i] in dt and target - numbers[i] != numbers[i]:
                return [dt[target - numbers[i]], i+1]
            dt[numbers[i]] = i + 1
        return [-1, -1]
        