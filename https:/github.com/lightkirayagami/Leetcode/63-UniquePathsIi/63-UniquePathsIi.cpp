// Last updated: 27/04/2026, 21:52:13
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int ans=0;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        ans=solve(0,0,grid.size(),grid[0].size(),grid,dp);
        return ans;
        
    }

    int solve(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
         if(i<0||i>=m||j<0|j>=n||grid[i][j]==1)
        {
            return  0;
        }
        if(i==m-1&&j==n-1)
        {
            return 1;
        }
       
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }



        int a=solve(i+1,j,m,n,grid,dp);
        int b=solve(i,j+1,m,n,grid,dp);
        dp[i][j]=a+b;

        return a+b;
    }
};