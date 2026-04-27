// Last updated: 27/04/2026, 21:48:42
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return ans(nums,target,nums.size(),dp);
        
    }

    int ans(vector<int>& nums, int target,int n,vector<int>&dp)
    {
        
        if(target==0)
        {
            return 1;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int ways=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target)
            ways=ways+ans(nums,target-nums[i],n,dp);
        }
        return dp[target]=ways;
    }
};