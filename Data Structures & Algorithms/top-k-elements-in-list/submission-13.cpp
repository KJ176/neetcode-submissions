class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int &num : nums) {
            freqMap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucketSort(n + 1);

        for(auto &it : freqMap) {
            bucketSort[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i = n; i >= 0; i--) {
            vector<int> vals = bucketSort[i];
            for(int val : vals) {
                if (k == 0) break;
                res.push_back(val);
                k--;
            }
            
        }

        return res;
    }
};
