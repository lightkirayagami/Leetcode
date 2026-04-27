// Last updated: 27/04/2026, 21:44:50
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0;
        long long maxsum=0;//globla max
        long long  currsum=0;//window ka max
        map<int,int>mp;
        

        for(int j=0;j<nums.size();j++)
        {
            currsum=currsum+nums[j];
            if(mp.find(nums[j])==mp.end())//not found
                mp.insert({nums[j],1});
            
            else
            {
                mp[nums[j]]++; //already there just increase itsw value(Freq);
            }


            if(j-i+1>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                currsum=currsum-nums[i];
                i++;
            }

            if(j-i+1==k)
            {
                if(mp.size()==k)
                maxsum=max(currsum,maxsum);

            }
            

        }

        return maxsum;
    }
};