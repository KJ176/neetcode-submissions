class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int> &candidates, int target, int start, vector<int> &subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (target < candidates[i]) return;
            subset.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, subset);
        return res;
    }
};
