class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dt = {}
        ans = []
        for s in strs:
            freq = [0] * 26
            key = ""
            for c in s:
                freq[ord(c) - ord('a')] += 1
            for i in range(26):
                key += '#' + str(freq[i])
            dt.setdefault(key, []).append(s)
        for k,v in dt.items():
            ans.append(v)
        return ans