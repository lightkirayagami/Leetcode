// Last updated: 27/04/2026, 21:51:08
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(201,vector<int>(202,-1));
        return solve(triangle,0,0,dp);
        
    }

    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp)
    {
        if(i==triangle.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int a=triangle[i][j]+solve(triangle,i+1,j,dp);
        int b=triangle[i][j]+solve(triangle,i+1,j+1,dp);
        return dp[i][j]=min(a,b);

    }
};