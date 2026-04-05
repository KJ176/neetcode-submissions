class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        int fleets = 1;

        double prevTime = (double)(target - pairs[0].first) / pairs[0].second;
        for (int i = 0; i<n; i++) {
            double currTime = (double)(target - pairs[i].first) / pairs[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
