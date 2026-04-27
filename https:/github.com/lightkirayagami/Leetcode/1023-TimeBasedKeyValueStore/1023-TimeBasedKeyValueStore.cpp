// Last updated: 27/04/2026, 21:46:21
class TimeMap {
public:
unordered_map<string,vector<pair<string,int>>>mp;
 vector<pair<string,int>>temp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key)==mp.end())
        {
            return "";
        }
        

       
       vector<pair<string,int>>& temp = mp[key];
    return bs(temp, timestamp);

        // string ans=bs(temp,timestamp);
        // return ans;
        
    }

    string bs(vector<pair<string,int>>&nums,int timestamp)
    {

        int start=0;
        string s="";
        int end=nums.size()-1;

        while(start<=end)
        {
            int mid=(start+end)/2;

            if(nums[mid].second==timestamp)
            {
                return nums[mid].first;
            }
            else if(nums[mid].second<timestamp)
            {
                s=nums[mid].first;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return s;

    }



};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */