class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, int target, vector<int> &subset, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0 or i >= nums.size()) {
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, target - nums[i], subset, i);
        subset.pop_back();
        backtrack(nums, target, subset, i + 1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        backtrack(nums, target, subset, 0);
        return res;
    }
};
