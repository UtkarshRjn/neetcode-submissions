class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        count = {}
        for elem in s:
            count[elem] = count.get(elem,0) + 1
        
        for elem in t:
            count[elem] = count.get(elem,0) - 1


        for i in range(26):
            c = chr(ord('a') + i)
            if count.get(c,0) != 0:
                return False
        
        return True