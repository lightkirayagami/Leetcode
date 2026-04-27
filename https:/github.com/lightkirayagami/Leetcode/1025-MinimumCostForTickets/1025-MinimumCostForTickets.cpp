// Last updated: 27/04/2026, 21:46:19
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return ans(days, costs, 0,0,dp);

    }

    int ans(vector<int>& days, vector<int>& costs, int currday, int currindex,vector<int>&dp) {

        if (currindex >= days.size()) {
            return 0;
        }
        if (dp[currindex] != -1) return dp[currindex];
        int actualDay = days[currindex];
        int i = findCeil(days,  actualDay+ 1);   // 1-day ticket covers today
        int j = findCeil(days, actualDay + 7);   // 7-day ticket
        int k = findCeil(days, actualDay + 30);

        int a = costs[0] + ans(days, costs, currday + 1, i,dp);
        int b = costs[1] + ans(days, costs, currday + 7, j,dp);
        int c = costs[2] + ans(days, costs, currday + 30, k,dp);
        return dp[currindex]=min({a, b, c});
    }

    int findCeil(vector<int> days, int currday) {
        int l = 0;
        int r = days.size() - 1;
        int res = days.size();
        while (l <= r) {
             int mid = (l+r)/2;
            if (days[mid] == currday) {
                return mid;
            } else if (days[mid] < currday) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};