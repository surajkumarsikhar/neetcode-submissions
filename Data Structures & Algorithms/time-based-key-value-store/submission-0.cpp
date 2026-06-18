class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto &timeVec = mp[key];
        int low = 0;
        string ans = "";
        int high = mp[key].size() - 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(timeVec[mid].first <= timestamp){
                ans = timeVec[mid].second;
                low = mid + 1;
            }else{
                high = mid - 1; 
            }
        }
        return ans;

    }
};
