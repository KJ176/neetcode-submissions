class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;
        for (int i = 0; i<nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            if (mapp.find(diff) != mapp.end()) 
                return { min(mapp[diff], i) , max(mapp[diff], i)};
            mapp[num] = i;
        }
        return {};
    }
};
