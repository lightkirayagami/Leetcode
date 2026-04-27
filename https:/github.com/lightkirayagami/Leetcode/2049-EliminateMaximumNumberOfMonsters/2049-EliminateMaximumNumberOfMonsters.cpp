// Last updated: 27/04/2026, 21:45:14
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<double> time(n, -1.0);
        for (int i = 0; i < n; i++) {
            time[i] = (double)dist[i] / speed[i];
        }

        sort(time.begin(), time.end());
        int ans = 0;
        for (int i = 0; i < n ; i++) {
          if(time[i]>i)
          {
            ans++;
          }
          else
          {
            break;
          }
        }

        return ans;
    }
};