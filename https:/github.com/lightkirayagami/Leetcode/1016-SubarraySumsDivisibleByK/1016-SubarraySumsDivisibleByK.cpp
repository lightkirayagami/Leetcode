// Last updated: 27/04/2026, 21:46:27
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int count=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int mod = (sum % k + k) % k;
            if(mp.find(mod)!=mp.end())
            {
                count=count+mp[mod];
            }
            if(mp.find(mod)!=mp.end())
            {
                mp[mod]++;
            }
            else 
            {
                mp[mod]++;
            }
        }
        return count;
        
    }
};