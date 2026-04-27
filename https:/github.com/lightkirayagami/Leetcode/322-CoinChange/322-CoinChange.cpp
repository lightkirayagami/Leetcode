// Last updated: 27/04/2026, 21:49:02
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans;
        int n=coins.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        ans=solve(coins,amount,0,dp);
       if (ans >= 10001) {
            return -1;
        }
        return ans;
        
        
    }

    int solve(vector<int>&coins,int amount,int curr,vector<vector<int>>&dp)
    {
        if(curr>=coins.size()||amount<0)
        {
            return 1000001;
        }
        if(amount==0)
        {
            return 0;
        }
        if(dp[curr][amount]!=-1)
        {
            return dp[curr][amount];
        }

        int pick=1+solve(coins,amount-coins[curr],curr,dp);
        int notpick=solve(coins,amount,curr+1,dp);

        dp[curr][amount]=min(pick,notpick);
        return dp[curr][amount];


    }   
};