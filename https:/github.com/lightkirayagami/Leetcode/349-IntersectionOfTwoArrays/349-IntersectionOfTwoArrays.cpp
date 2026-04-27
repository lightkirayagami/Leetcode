// Last updated: 27/04/2026, 21:48:50
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,bool>mp;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=true;
        }
        
        
        for(int i=0;i<nums2.size();i++)
        {
            auto it=mp.find(nums2[i]);
            if(it!=mp.end()&&it->second==true)
            {
                ans.push_back(nums2[i]);
                it->second=false;
            }
        }
        return ans;
        
    }
};