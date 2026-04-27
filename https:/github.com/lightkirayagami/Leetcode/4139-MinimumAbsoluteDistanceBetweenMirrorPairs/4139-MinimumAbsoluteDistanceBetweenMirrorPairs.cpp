// Last updated: 27/04/2026, 21:44:35
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            int revele=reverse(nums[i]);

            if(mp.find(nums[i])!=mp.end())
            {
                ans=min(abs(mp[nums[i]]-i),ans);
               
            }
             mp[revele]=i;



           
        }

        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
        

        

        
    }

    int reverse(int nums)
    {

        int ans=0;

        while(nums>0)
        {
            int endigit=nums%10;
            nums=nums/10;

            ans=ans*10+endigit;
        }

        return ans;

    }
};