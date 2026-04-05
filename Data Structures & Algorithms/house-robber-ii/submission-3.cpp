class Solution {
private:
    int helper(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for(int num : nums) {
            int temp = max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(helper(nums1), helper(nums2));
    }
};
