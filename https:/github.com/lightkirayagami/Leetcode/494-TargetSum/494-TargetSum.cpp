// Last updated: 27/04/2026, 21:48:08
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);
        // Memoization table: dp[index][sum + offset]
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * total + 1, -1));
        return solve(nums, target, nums.size(), dp, total);
    }

    int solve(vector<int>& nums, int sum, int n, vector<vector<int>>& dp,
              int offset) {

        if (n == 0) {
            return (sum == 0) ? 1 : 0;
        }
        if ((sum + offset) < 0 || (sum + offset) > 2 * offset) {
            return 0;
        }
        if (dp[n][sum + offset] != -1) {
            return dp[n][sum + offset];
        }

        int a = solve(nums, sum + nums[n - 1], n - 1, dp, offset);
        int b = solve(nums, sum - nums[n - 1], n - 1, dp, offset);
        return dp[n][sum + offset] = a + b;
    }
};