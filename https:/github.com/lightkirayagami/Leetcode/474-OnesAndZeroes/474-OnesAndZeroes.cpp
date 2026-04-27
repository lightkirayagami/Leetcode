// Last updated: 27/04/2026, 21:48:10
class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {

        
        memset(dp,-1,sizeof(dp));

        vector<pair<int, int>> nums;
        for (int i = 0; i < strs.size(); i++) {
            int num0 = 0;
            int num1 = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    num0++;
                } else {
                    num1++;
                }
            }
            nums.push_back({num0, num1});
        }

        int ans = solve(nums, m, n, 0);
        if (ans < 0) {
            return 0;
        }

        return ans;
    }

    int solve(vector<pair<int, int>>& nums, int m, int n,int i) {
        // if(m==0&&n==0)
        // {
        //     return 0;
        // }
        if (i == nums.size()) {
            return 0;
        }
        if(dp[i][m][n]!=-1)
        {
            return dp[i][m][n];
        }
        // if(m<0||n<0)
        // {
        //     return -1e9;
        // }

        int pick = 0;
        if (m >= nums[i].first && n >= nums[i].second) {
            pick =
                1 + solve(nums, m - nums[i].first, n - nums[i].second,i+1);
        }
        int notpick = solve(nums, m, n, i + 1);

        dp[i][m][n]=max(pick, notpick);

        return max(pick, notpick);
    }
};