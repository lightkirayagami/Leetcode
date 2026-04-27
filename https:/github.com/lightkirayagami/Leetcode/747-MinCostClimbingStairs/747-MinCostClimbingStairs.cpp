// Last updated: 27/04/2026, 21:47:18
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int>dp(cost.size()+1,-1);
        int ans1=ans(cost,0,dp);
        int ans2=ans(cost,1,dp);
        return min(ans1,ans2);

        
    } 

    int ans(vector<int>& cost,int curr,vector<int>&dp)
    {
        if(curr>=cost.size())
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }

        int a=cost[curr]+ans(cost,curr+1,dp);
        int b=cost[curr]+ans(cost,curr+2,dp);
        return dp[curr]=min(a,b);

    }  

};