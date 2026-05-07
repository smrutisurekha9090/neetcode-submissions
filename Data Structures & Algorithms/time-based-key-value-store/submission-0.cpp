class TimeMap {
public:
    unordered_map<string , vector<pair<int,string>>>mp;
    TimeMap() {
    }
    
    //TC-0(1)
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    //TC -0(logn)
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        auto &vec =mp[key];
        int low=0;
        int high=vec.size()-1;
        string ans = "";

        while(low <= high){
            int mid = low +(high-low)/2;

            if(vec[mid].first == timestamp){
                return vec[mid].second;
            }

            if(vec[mid].first < timestamp){
                ans = vec[mid].second;
                low = mid+1;
            }else{
                high =mid-1;
            }
        }
        return ans;
    }
};
