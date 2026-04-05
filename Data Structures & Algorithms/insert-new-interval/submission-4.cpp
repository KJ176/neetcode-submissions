class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int n = intervals.size();
        int l = 0, r = n - 1;
        int insertPosition = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int intervalStart = intervals[mid][0];
            if (intervalStart < start) {
                l = mid + 1;
                insertPosition = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        intervals.insert(intervals.begin() + insertPosition, newInterval);

        vector<vector<int>> res;
        for(auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
