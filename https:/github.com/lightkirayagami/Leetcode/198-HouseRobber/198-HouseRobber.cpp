// Last updated: 27/04/2026, 21:50:11
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n+1,0);

        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<dp.size();i++)
        {
            int a=nums[i-1]+dp[i-2];
            int b=dp[i-1];

            dp[i]=max(a,b);
        }
        return dp[n];
        
    }
};