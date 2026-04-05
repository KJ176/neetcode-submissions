class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        for i, val in enumerate(nums):
            diff = target - val
            if diff in hash:
                return [hash[diff], i]
            hash[val] = i