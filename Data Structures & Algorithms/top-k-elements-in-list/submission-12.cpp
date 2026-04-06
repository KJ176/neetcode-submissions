class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1, vector<int>());

        for(auto& it : freq) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i = n; i >= 0; i --) {
            for(int val : buckets[i]) {
                res.push_back(val);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;

    }
};
