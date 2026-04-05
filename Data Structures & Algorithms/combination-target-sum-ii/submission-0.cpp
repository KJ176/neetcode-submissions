class Solution {
private:
    set<vector<int>> res;

    void backtrack(vector<int> &candidates, int target, int i, vector<int> &subset) {
        if (target == 0) {
            res.insert(subset);
            return;
        }
        if (target < 0 or i == candidates.size()) {
            return;
        }
        subset.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, subset);
        subset.pop_back();
        backtrack(candidates, target, i + 1, subset);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, subset);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
