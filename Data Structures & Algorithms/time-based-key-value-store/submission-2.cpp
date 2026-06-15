class TimeMap {
public:
    map<pair<string,int> , string>timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find({key,timestamp}) != timeMap.end()) return timeMap[{key,timestamp}];
        int ts = timestamp;
        string returnAns = "";
        for(auto it : timeMap){
            if(it.first.second < ts && it.first.first == key){
                returnAns = it.second;
                timeMap[{key,timestamp}] = it.second;
            }
        }
        if(returnAns.size() >  0) return returnAns;
        return "";
    }
};
