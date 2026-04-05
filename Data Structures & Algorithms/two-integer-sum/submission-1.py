class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        # hash = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in hash:
                return [hash[diff], i]
            hash[nums[i]] = i