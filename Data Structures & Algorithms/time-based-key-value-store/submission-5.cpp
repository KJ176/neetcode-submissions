class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if (store.count(key) == 0) return "";
        const vector<pair<string, int>> &values = store[key];
        int l = 0, r = values.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            string val = values[mid].first;
            int time = values[mid].second;
            if (time == timestamp) {
                return val;
            } else if (time < timestamp) {
                res = val; //Highest so far
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
