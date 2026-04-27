// Last updated: 27/04/2026, 21:45:54
class Solution {
public:
 static const int MOD = 1e9 + 7;

    int countVowelPermutation(int n) {
        
        long long ans = 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1));
        for (int i = 0; i < 5; i++) {
            ans = (ans + solve(n, i, dp))%MOD;
        }
        return ans;
    }

    long long solve(int n, int i, vector<vector<long long>>& dp) {
        if (n == 1) {
            return 1;
        }
        if (dp[n][i] != -1) {
            return dp[n][i];
        }

        long long ans = 0;

        if (i == 0) // a
        {
            ans = ans + solve(n - 1, 1, dp); // e
            ans = ans + solve(n - 1, 2, dp); // i
            ans = ans + solve(n - 1, 4, dp); // u
        } else if (i == 1)                   // e
        {
            ans = ans + solve(n - 1, 2, dp); // i
            ans = ans + solve(n - 1, 0, dp); // a
        } else if (i == 2)                   // i
        {
            ans = ans + solve(n - 1, 3, dp); // o
            ans = ans + solve(n - 1, 1, dp); // e
            // ans = ans + solve(n - 1, 4); // u
            // ans = ans + solve(n - 1, 0); // a
        } else if (i == 3) // o
        {

            ans = ans + solve(n - 1, 2, dp); // i
        } else {
            ans += solve(n - 1, 2, dp);
            ans += solve(n - 1, 3, dp); // a
        }

        dp[n][i] = ans%MOD;
        return ans;
    }
};