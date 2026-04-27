// Last updated: 27/04/2026, 21:48:28
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        int W = 10001;

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));

        return ans(nums, sum / 2, nums.size(), dp);
    }

    bool ans(vector<int>& nums, int sum, int n, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        bool a = false;
        if (nums[n - 1] <= sum) {
            a = ans(nums, sum - nums[n - 1], n - 1,dp);
        }

        bool b = ans(nums, sum, n - 1, dp);
        return dp[n][sum] = a || b;
    }
};