// Last updated: 27/04/2026, 21:46:03
class Solution {
public:
    int tribonacci(int n) {
           vector<int>dp(n+1,-1);
        return totalways(n,dp);
    }
     int totalways(int n,vector<int>&dp)
    {
        if(n<=0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
          if(n==2)
        {
            return 1;
        }
        if(dp[n]!=-1)
    {
        return dp[n];
    }
      
    int onejump=totalways(n-1,dp);
    int twojump=totalways(n-2,dp);
    int thirdjump=totalways(n-3,dp);
   
    int sum=onejump+twojump+thirdjump;
        return dp[n]=sum;
    }
};