class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;
        for(int num : nums) {
            int temp = curMax;
            curMax = max(num, max(temp * num, curMin * num));
            curMin = min(num, min(temp * num, curMin * num));
            res = max(res , curMax);
        }
        return res;
    }
};
