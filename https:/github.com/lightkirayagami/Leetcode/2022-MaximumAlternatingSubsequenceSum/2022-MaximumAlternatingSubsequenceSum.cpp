// Last updated: 27/04/2026, 21:45:21
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long ans = 0;
        vector<vector<long long >> dp(nums.size() + 1, vector<long long>(2, -1));

        ans = solve(nums, 0, 0, dp);
        return ans;
    }

    long long  solve(vector<int>& nums, int i, int flag, vector<vector<long long>>& dp) {
        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][flag] != -1) {
            return dp[i][flag];
        }

        long long  pick = 0;

        if (flag == 0) {
            pick = nums[i] + solve(nums, i + 1, 1, dp);
        } else {
            pick =  solve(nums, i + 1, 0, dp) - nums[i];
        }

        long long  notpick =  (solve(nums, i + 1, flag, dp));

        dp[i][flag] = max(pick, notpick);

        return max(pick, notpick);
    }
};