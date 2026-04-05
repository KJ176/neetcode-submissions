class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        st = []
        l = r = 0
        while (r < n):
            while st and temperatures[st[-1]] < temperatures[r]:
                res[st[-1]] = r - st[-1]
                st.pop()
            st.append(r)
            r+=1
        return res