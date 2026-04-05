class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];
            if (mpp.find(req) != mpp.end()) {
                int j = mpp[req];
                return {min(i, j), max(i, j)};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
