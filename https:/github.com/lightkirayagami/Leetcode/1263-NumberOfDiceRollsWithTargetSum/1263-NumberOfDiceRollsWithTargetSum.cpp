// Last updated: 27/04/2026, 21:46:00
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
          vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
        // memset(dp,-1,sizeof(dp));
        int modulo=1000000007;
        
     long long ans=solve(n,k,target,dp,modulo);
        return ans;
        
        
    };
    long long int solve(int n, int k, int target,vector<vector<long long>>&dp,int modulo)
    {
        if(n==0)
        {
            if(target==0)
                return 1;
            return 0;
        }
        if(target<0)
            return 0;
        if(dp[n][target]!=-1)
        {
            return dp[n][target]%modulo;
        }
        long long int ways=0;
        for(int i=1;i<=k;i++)
        {
            ways=(ways%modulo+solve(n-1,k,target-i,dp,modulo)%modulo)%modulo;
        }
        return dp[n][target]=ways;
        
    }
};