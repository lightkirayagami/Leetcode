// Last updated: 27/04/2026, 21:52:02
class Solution {
public:
    int minDistance(string word1, string word2) {

        int ans=0;
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        ans=solve(word1,word2,0,0,word1.size(),word2.size(),dp);
        
        return ans;
        
    }

    int solve(string word1,string word2,int i,int j,int m,int n,vector<vector<int>>&dp)

    {
        if(i==m)
        {
            return n-j;
        }
        if(j==n)
        {
            return m-i;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int res=0;



        if(word1[i]==word2[j])
        {
            res=solve(word1,word2,i+1,j+1,m,n,dp);
        }
        else
        {
            int a=1+solve(word1,word2,i+1,j,m,n,dp);
            int b=1+solve(word1,word2,i,j+1,m,n,dp);
            int c=1+solve(word1,word2,i+1,j+1,m,n,dp);

            a=min(a,b);
            a=min(a,c);
            res=a;
        }

        return dp[i][j]=res;
    }
};