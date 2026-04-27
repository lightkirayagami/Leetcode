// Last updated: 27/04/2026, 21:48:04
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int ans=0;
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        ans=solve(amount,coins,0,dp);
        return ans;
    }

    int solve(int amount,vector<int>&coins,int i,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i==coins.size())
        {
            return 0;
        }
        if(dp[amount][i]!=-1)
        {
            return dp[amount][i];
        }


        int pick=0;
        if(coins[i]<=amount)
        {
            pick=solve(amount-coins[i],coins,i,dp);
        }
        int notpick=solve(amount,coins,i+1,dp);
        dp[amount][i]=pick +notpick;

        return pick+notpick;
    }

};