class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s1 = {}
        for n in s:
            s1[n] = s1.get(n, 0) + 1
        for n in t:
            if s1.get(n):
                s1[n] -= 1
                if s1[n] == 0:
                    del s1[n]
        return len(s1) == 0
