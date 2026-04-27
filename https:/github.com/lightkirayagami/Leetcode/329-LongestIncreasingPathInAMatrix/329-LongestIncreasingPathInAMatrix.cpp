// Last updated: 27/04/2026, 21:48:59
class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
       

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 ans=max(ans,dfs(i,j,m,n,matrix,dp));

            }
        }

        return ans;
        
    }

    int dfs(int i,int j,int m,int n,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(i<0||i>=m||j<0||j>=n)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {

            return dp[i][j];
        }

        int ans=1;

       ;
        for(int k=0;k<4;k++)
        {
            int xdx=dx[k]+i;
            int ydy=dy[k]+j;

            if(xdx>=0&&xdx<m&&ydy>=0&&ydy<n&&matrix[i][j]<matrix[xdx][ydy])
            {
                ans=max(ans,1+dfs(xdx,ydy,m,n,matrix,dp));
            }
          
        }
        dp[i][j]=ans;
        return ans;
    }

};