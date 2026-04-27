// Last updated: 27/04/2026, 21:49:06
class Solution {
public:
    int maxProfit(vector<int>& prices) {
           int dp[10001][10];
        memset(dp,-1,sizeof(dp));
        return maximumprofit(prices,0,1,dp);
        
        
        
    }
        
int maximumprofit(vector<int>& prices,int currentindex,int canbuy, int dp[10001][10])
    {
        if(currentindex>=prices.size())
        {
            return 0;
        }
        if(dp[currentindex][canbuy]!=-1)
        {
            return dp[currentindex][canbuy];
        }
        
        
        if(canbuy==1)
        {
            int idle=maximumprofit(prices,currentindex+1,canbuy,dp);
                int buy=(-prices[currentindex])+maximumprofit(prices,currentindex+1,0,dp);
                   return dp[currentindex][canbuy]=  max(idle,buy);
        }
        else
        {
                        int idle=maximumprofit(prices,currentindex+1,canbuy,dp);
                        int sell=(prices[currentindex])+maximumprofit(prices,currentindex+2,1,dp);
                              return dp[currentindex][canbuy]= max(idle,sell);


        }
    }
};