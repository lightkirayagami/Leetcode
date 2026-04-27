// Last updated: 27/04/2026, 21:46:30
class Solution {
public:
    int fib(int n) {
       vector<int>dp(n+1,-1);
        return totalways(n,dp);
        
    };
   int totalways(int targstr, vector<int>&dp)
    {
         int m=pow(10,9)+7;
        if(targstr==0)
        {
            return 0;
        }
        if(targstr==1)
        {
            return 1;
        }
        if(dp[targstr]!=-1)
        {
        return dp[targstr]%m;
        }
      
    long long int onejump=totalways(targstr-1,dp);
    long long int twojump=totalways(targstr-2,dp);
    long long int sum=(onejump+twojump)%m;
        return dp[targstr]=sum;
    };
};