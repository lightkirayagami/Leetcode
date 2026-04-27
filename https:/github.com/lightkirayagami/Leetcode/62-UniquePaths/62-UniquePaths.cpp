// Last updated: 27/04/2026, 21:52:15
class Solution {
public:
    int uniquePaths(int m, int n) {


        int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        ans=solve(0,0,m,n,dp);
        return ans;
        
    }

    int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i<0||i>=m||j<0;j>=n)
        {
            return 0;
        }

        if(i==m-1||j==n-1)
        {
            return 1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }



        int a=solve(i+1,j,m,n,dp);
        int b=solve(i,j+1,m,n,dp);
        dp[i][j]=a+b;

        return a+b;
    }



};