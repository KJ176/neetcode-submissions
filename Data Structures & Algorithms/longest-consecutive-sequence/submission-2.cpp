class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;
        for(int num : st) {
            if (st.count(num - 1) == 0) {
                int length = 1;
                while(st.count(num + length) > 0) {
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};