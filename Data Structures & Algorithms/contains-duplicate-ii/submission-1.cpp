class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_set<int> window;
        for(int r = 0; r < nums.size(); r++) {
            if ((r - l) > k) {
                window.erase(nums[l]);
                l++;
            }
            if (window.count(nums[r])) {
                return true;
            }
            window.insert(nums[r]);
        }
        return false;
    }
};