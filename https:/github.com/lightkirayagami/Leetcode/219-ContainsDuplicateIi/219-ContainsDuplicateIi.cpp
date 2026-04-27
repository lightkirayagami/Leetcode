// Last updated: 27/04/2026, 21:49:46
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        map<int,int>m;
        int n=nums.size();
       k++;
        if(k>=n)
        {
            for(int i=0;i<n;i++)
            {
                m[nums[i]]++;
            }
            for(auto it:m)
            {
                if(it.second>1)
                {
                    return true;
                }
            }
            return false;
        }
        
        bool ans=false;
        
        
        while(j<n)
        {
            m[nums[j]]++;
            if(m[nums[j]]>1 )
            {
                return true;
            }
            if(j-i+1<k)
            {
                j++;
            }
             else if(j-i+1==k)
            {
                
                m[nums[i]]--;
                i++;
                j++;
            }
        }
        return ans;
        
    }
};