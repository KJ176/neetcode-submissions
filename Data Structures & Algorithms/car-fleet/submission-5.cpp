class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i ++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        int fleets = 0;
        double maxSoFar = 0;
        for(auto& car: pairs) {
            double time = (double)(target - car.first) / car.second;
            if(maxSoFar < time) {
                maxSoFar = time;
                fleets++;
            }
        }
        return fleets;
    }
};
