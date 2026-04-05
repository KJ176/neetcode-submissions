class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> store;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({ value, timestamp });
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<string, int>> values = store[key];

        int l = 0, r = values.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (values[mid].second < timestamp) {
                res = values[mid].first;
                l = mid + 1;
            } else if (values[mid].second > timestamp) {
                r = mid - 1;
            } else {
                return values[mid].first;
            }
        }
        return res;
    }
};
