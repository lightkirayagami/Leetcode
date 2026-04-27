// Last updated: 27/04/2026, 21:48:55
class Solution {
public:
    int integerBreak(int n) {

        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
        }
        vector<int>dp(n+1,-1);
        return solve(nums,n,nums.size(),dp);
        
    }

    long long int solve(vector<int>nums,int target,int n,vector<int>&dp)
    {
        if (target == 0) return 1;
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        
        int prod=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= target) {
                int cur = nums[i] * solve(nums, target - nums[i], n,dp);
                prod = max(prod, cur);
            }
        }
        
        return dp[target]=prod;
    }
};