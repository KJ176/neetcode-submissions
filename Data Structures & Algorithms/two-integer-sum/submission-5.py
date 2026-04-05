class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        for i, val in enumerate(nums):
            diff = target - val
            if diff in hash:
                return [min(i, hash[diff]), max(i, hash[diff])]
            hash[val] = i