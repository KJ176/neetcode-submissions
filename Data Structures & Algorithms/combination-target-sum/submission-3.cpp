class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int target, int start, vector<int> &subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) return;
            subset.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, subset);
        return res;
    }
};
