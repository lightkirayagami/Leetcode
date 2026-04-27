// Last updated: 27/04/2026, 21:51:29
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int m=s1.size();
        int n=s2.size();
        int o=s3.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        if(m+n!=o)
        {
            return false;
        }


        int ans=false;
        ans=solve(0,0,m,n,o,s1,s2,s3,dp);
        return ans;
        
    }

    bool solve(int i,int j,int m,int n,int o,string s1, string s2, string s3,vector<vector<int>>&dp)
    {
        if(i+j==o)
        {
            return true;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        bool ans=false;


        if(s1[i]==s3[i+j]&&s2[j]==s3[i+j])
        {
            ans=ans||solve(i+1,j,m,n,o,s1,s2,s3,dp);
            ans=ans||solve(i,j+1,m,n,o,s1,s2,s3,dp);
        }
        else if(s1[i]==s3[i+j])
        {
            ans=ans||solve(i+1,j,m,n,o,s1,s2,s3,dp);
        }
        else if(s2[j]==s3[i+j])
        {
            ans=ans||solve(i,j+1,m,n,o,s1,s2,s3,dp);
        }
        dp[i][j]=ans;

        return ans;



    }

};