// Last updated: 27/04/2026, 21:46:01
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int ans = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        ans = solve(0, 0, m, n, text1, text2,dp);
        return ans;
    }

    int solve(int i, int j, int m, int n, string& t1, string& t2,vector<vector<int>>&dp) {
        if (i == m || j == n ) {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if (t1[i] == t2[j]) {
            return dp[i][j]=1 + solve(i + 1, j + 1, m, n, t1, t2,dp);
        }
        else
        {
        return dp[i][j]=max(solve(i + 1, j, m, n, t1, t2,dp),
                   solve(i, j + 1, m, n, t1, t2,dp));
        }
    }

};