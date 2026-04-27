// Last updated: 27/04/2026, 21:49:09
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int prev=-1;
        int ans;
        map<pair<int,int>,int>mp;
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        ans=solve(nums,0,prev,dp);
        return ans;
        
    }

    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
       if(dp[i][prev+1]!=-1)
       {
        return dp[i][prev+1];
       }


        int pick=0;

        if(prev==-1||nums[i]>nums[prev])
        {
            pick=1+solve(nums,i+1,i,dp);
        }
        int notpick=solve(nums,i+1,prev,dp);
       
       dp[i][prev+1]=max(pick,notpick);
        return max(pick,notpick);
    }
};