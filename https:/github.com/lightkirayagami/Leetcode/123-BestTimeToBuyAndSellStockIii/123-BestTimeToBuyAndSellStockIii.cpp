// Last updated: 27/04/2026, 21:51:03
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int dp[100001][2][5];
        memset(dp,-1,sizeof(dp));
        return maximumprofit(prices,0,1,2,dp);
        
    }
        
 int maximumprofit(vector<int>& prices,int currentindex,int canbuy,int transactioncount, int dp[100001][2][5])
    {
        if(currentindex>=prices.size()||transactioncount==0)
        {
            return 0;
        }
        if(dp[currentindex][canbuy][transactioncount]!=-1)
        {
            return dp[currentindex][canbuy][transactioncount];
        }
        
        
        if(canbuy==1)
        {
            int idle=maximumprofit(prices,currentindex+1,canbuy,transactioncount,dp);
                int buy=(-prices[currentindex])+maximumprofit(prices,currentindex+1,0,transactioncount,dp);
                   return dp[currentindex][canbuy][transactioncount]=  max(idle,buy);
        }
        else
        {
                        int idle=maximumprofit(prices,currentindex+1,canbuy,transactioncount,dp);
                        int sell=(prices[currentindex])+maximumprofit(prices,currentindex+1,1,transactioncount-1,dp);
                              return dp[currentindex][canbuy][transactioncount]= max(idle,sell);


        }
    }
};