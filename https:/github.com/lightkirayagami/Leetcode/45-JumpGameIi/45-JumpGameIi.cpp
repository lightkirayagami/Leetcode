// Last updated: 27/04/2026, 21:52:34
class Solution {
public:
    int jump(vector<int>& nums) {

        int ans=0;
        vector<int>dp(10001,-1);
        ans=solve(nums,0,dp);

        return ans;


        
    }


    int solve(vector<int>&nums,int pos,vector<int>&dp)
    {
        if(pos>=nums.size()-1)
        {
            return 0;
        }

        if(nums[pos]==0)
        {
            return 10001;
        }

        if(dp[pos]!=-1)
        {
            return dp[pos];
        }


        int ans=10001;

        for(int i=1;i<=nums[pos];i++)
        {
            int temp=1+solve(nums,pos+i,dp);
            ans=min(ans,temp);
        }
        dp[pos]=ans;
        return ans;


    }
};