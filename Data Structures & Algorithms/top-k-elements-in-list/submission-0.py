class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countMap = {}
        for num in nums:
            countMap[num] = 1 + countMap.get(num, 0)
        
        arr = []
        for num, count in countMap.items():
            arr.append([count,num])
        arr.sort()

        res = []
        while len(res) < k:
            res.append(arr.pop()[1])
        return res