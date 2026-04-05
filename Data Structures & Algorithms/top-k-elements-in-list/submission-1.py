class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countMap = {}

        for num in nums:
            countMap[num] = 1 + countMap.get(num, 0)
        
        freqMap = [[] for _ in range(len(nums) + 1)]
        for num, count in countMap.items():
            freqMap[count].append(num)
        
        res = []
        for i in range(len(freqMap) - 1, 0, -1):
            if len(freqMap[i]) > 0:
                res.extend(freqMap[i])
                if len(res) == k:
                    break
        return res
