class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // {distance, point}
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        for(vector<int> point: points) {
            int distance = point[0]*point[0] + point[1]*point[1];
            maxHeap.push({distance, {point[0], point[1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            auto [dist, point] = maxHeap.top();
            maxHeap.pop();
            res.push_back({point.first, point.second});
        }
        return res;
    }
};
