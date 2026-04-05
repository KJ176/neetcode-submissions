class Solution {
private:
    int rob_basic(vector<int>& nums) {
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
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(rob_basic(nums1), rob_basic(nums2));
    }
};
