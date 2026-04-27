// Last updated: 27/04/2026, 21:49:18
class Solution {
public:
    int numSquares(int n) {

        vector<int>sq;
        int i=1;
       
        while(i*i<=n)
        {
            sq.push_back(i*i);
            i++;
        }
         vector<vector<int>>dp(n+1,vector<int>(sq.size()+1,-1));

        return solve(n,sq,sq.size(),dp); 
    }

    int solve(int amount,vector<int>&sq,int n,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(n==0)
        {
            return 10001;
        }
        if(dp[amount][n]!=-1)
        {
            return dp[amount][n];
        }
        int pick=10001;
        if(sq[n-1]<=amount)
        {
            pick=1+solve(amount-sq[n-1],sq,n,dp);
        }
        int pnot=solve(amount,sq,n-1,dp);
        return dp[amount][n]=min(pnot,pick);
    }

};