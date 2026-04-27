// Last updated: 27/04/2026, 21:47:21
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int a = 0;

        for (int i = 0; i < n; i++) {
            if (a < nums[i]) {
                a = nums[i];
            }
        }

        vector<int> freq(a + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]] = nums[i] + freq[nums[i]];
        }
        vector<int> dp(a + 2, -1);
        n = freq.size();

        return solve(freq, n, dp);
    }

    int solve(vector<int>& freq, int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if(n==1)
        {
            return freq[n-1];
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int a = freq[n - 1] + solve(freq, n - 2, dp);
        int b = solve(freq, n - 1, dp);
        return dp[n] = max(a, b);
    }
};