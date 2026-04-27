// Last updated: 27/04/2026, 21:52:12
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        

        int ans=0;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        ans=solve(0,0,grid.size(),grid[0].size(),grid,dp);
        return ans;
    }

    int solve(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==m||j==n)
        {
            return 1000001;
        }
        if(i==m-1&&j==n-1)
        {
            return grid[i][j];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int ans1=grid[i][j]+solve(i+1,j,m,n,grid,dp);
        int ans2=grid[i][j]+solve(i,j+1,m,n,grid,dp);
        dp[i][j]=min(ans1,ans2);
        return min(ans1,ans2);
    }
};