// Last updated: 27/04/2026, 21:45:46
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();

        int tsum = 0;
        for (int i = 0; i < n; i++) {
            tsum = tsum + nums[i];
        }

       int window = n - k;
       if(window==0)
       {
        return tsum;
       }

        int i = 0;

        int ans = INT_MIN;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum = sum + nums[j];

            // while (j - i + 1 == window) {
            //     ans = max(ans, tsum - sum);

            //     sum=sum-nums[i];
            //     i++;
            // }

            if(j-i+1>window)
            {
                sum=sum-nums[i];
                i++;
            }
            if(j-i+1==window)
            {
                ans = max(ans, tsum - sum);
            }


            

           
        }
        return ans;
    }
};