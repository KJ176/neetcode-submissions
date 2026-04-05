class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return t
        
        mapt, window = {}, {}
        for c in t:
            mapt[c] = 1 + mapt.get(c, 0)
        
        res = ''
        resLen = float("inf")
        have, need = 0, len(mapt)
        l = 0
        for r in range(len(s)):
            window[s[r]] = 1 + window.get(s[r], 0)
            if s[r] in mapt and window[s[r]] == mapt[s[r]]:
                have += 1
            while have == need:
                if resLen > (r - l + 1):
                    resLen = r - l + 1
                    res = s[l:r+1]
                window[s[l]] -= 1
                if s[l] in mapt and window[s[l]] < mapt[s[l]]:
                    have -= 1
                l+=1
        if resLen > float("-inf"):
            return res
        return ""
