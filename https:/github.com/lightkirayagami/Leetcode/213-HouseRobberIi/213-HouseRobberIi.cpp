// Last updated: 27/04/2026, 21:49:51
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>v1;
        vector<int>v2;
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        if(n<=1)
        {
            return nums[0];
        }
        for(int i=0;i<n-1;i++)
        {
            v1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++)
        {
            v2.push_back(nums[i]);
        }

        return max(ans(v1,0,dp1),ans(v2,0,dp2));
        
    }
    int ans(vector<int>&nums,int curr,vector<int>&dp)
    {
        if(curr>=nums.size())
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }

        int one=nums[curr]+ans(nums,curr+2,dp);
        int two=ans(nums,curr+1,dp);
        return dp[curr]=max(one,two);

    }
};