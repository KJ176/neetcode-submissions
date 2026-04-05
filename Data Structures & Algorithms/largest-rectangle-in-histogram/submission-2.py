class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        maxArea = 0

        for i,height in enumerate(heights):
            if stack and stack[-1][-1] > height:
                poppedHeight = [-1, -1]
                while stack and stack[-1][-1] > height:
                    poppedHeight = stack.pop()
                    maxArea = max(maxArea, (i-poppedHeight[0]) * poppedHeight[1])
                stack.append([poppedHeight[0], height])
            else:
                stack.append([i, height])
        while stack:
            poppedHeight = stack.pop()
            maxArea = max(maxArea, (n - poppedHeight[0]) * poppedHeight[1])

        return maxArea