class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq_array = [0]*26
        for char in s:
            freq_array[ord(char) - ord('a')] += 1
        for char in t:
            freq_array[ord(char) - ord('a')] -= 1
        for freq in freq_array:
            if freq != 0:
                return False
        return True