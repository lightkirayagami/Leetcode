// Last updated: 27/04/2026, 21:46:36
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=10000001;
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        for(int column=0;column<n;column++)
        {
            int tempans=solve(0,column,m,n,matrix,dp);
             ans=min(ans,tempans);
            
        }
        return ans;
        
    };
    int solve(int row,int column,int m,int n,vector<vector<int>>& matrix,int dp[101][101])
    {
        if(column<0||column>=n)
        {
            return 100001;
        }
        if(row==m-1)
        {
            return matrix[row][column];
        }
        if(dp[row][column]!=-1)
        {
            return dp[row][column];
        }
        
        int left=matrix[row][column]+solve(row+1,column-1,m,n,matrix,dp);
        int down=matrix[row][column]+solve(row+1,column,m,n,matrix,dp);
        int right=matrix[row][column]+solve(row+1,column+1,m,n,matrix,dp);
       
        
        return dp[row][column]=min(left,min(down,right));
    
    }
};