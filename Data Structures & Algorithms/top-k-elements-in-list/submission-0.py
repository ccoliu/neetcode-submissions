class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dt = Counter(nums)
        
        return [items[0] for items in dt.most_common(k)]