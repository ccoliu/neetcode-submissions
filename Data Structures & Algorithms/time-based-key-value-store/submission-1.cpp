class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        int n = mp[key].size();
        if (n == 0) return "";
        int l = 0, r = n - 1;
        string status = "";

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (mp[key][mid].second > timestamp) {
                r = mid - 1;
            }
            else {
                status = mp[key][mid].first;
                l = mid + 1;
            }
        }
        return status;
    }
};
