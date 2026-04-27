// Last updated: 27/04/2026, 21:48:48
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1;
        map<int,int>m2;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            m1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            m2[nums2[i]]++;
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            auto itr=m2.find(nums1[i]);
            
            if(itr!=m2.end()&&itr->second>0)
            {
                itr->second--;
                ans.push_back(itr->first);
            }
        }
        return ans;
        
    }
};