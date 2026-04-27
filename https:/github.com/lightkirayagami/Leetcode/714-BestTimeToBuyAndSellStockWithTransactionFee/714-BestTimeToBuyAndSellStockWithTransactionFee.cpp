// Last updated: 27/04/2026, 21:47:28
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
          int dp[100091][10];
        memset(dp,-1,sizeof(dp));
        return maximumprofit(prices,0,1,dp,fee);
    }
    int maximumprofit(vector<int>& prices,int currentindex,int canbuy, int dp[100001][10],int fee)
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
            int idle=maximumprofit(prices,currentindex+1,canbuy,dp,fee);
                int buy=(-prices[currentindex])+maximumprofit(prices,currentindex+1,0,dp,fee);
                   return dp[currentindex][canbuy]=  max(idle,buy);
        }
        else
        {
                        int idle=maximumprofit(prices,currentindex+1,canbuy,dp,fee);
                        int sell=(prices[currentindex])+(-fee)+maximumprofit(prices,currentindex+1,1,dp,fee);
                              return dp[currentindex][canbuy]= max(idle,sell);


        }
    }
};