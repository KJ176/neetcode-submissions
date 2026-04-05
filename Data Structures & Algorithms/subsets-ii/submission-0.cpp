class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, vector<int> &subset, int start) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); i++) {
            if ( i > start and nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            backtrack(nums, subset, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, subset, 0);
        return res;
    }
};
