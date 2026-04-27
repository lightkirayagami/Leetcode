// Last updated: 27/04/2026, 21:49:44
class Solution {
public:
    int maximalSquare(vector<vector<char>>& nums) {


        int ans=0;

        int m=nums.size();
        int n=nums[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,solve(i,j,m,n,nums,dp));
            }
        }

        return ans*ans;
        
    }

    int solve(int i,int j,int m,int n,vector<vector<char>>&nums,vector<vector<int>>&dp)
    {
        if(i<0||j<0||i>=m||j>=n||nums[i][j]=='0')
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;

        if(nums[i][j]=='1')
        {
            ans=1+min({solve(i+1,j,m,n,nums,dp),solve(i,j+1,m,n,nums,dp),solve(i+1,j+1,m,n,nums,dp)});
        }
        dp[i][j]=ans;

        return ans;
    }
};