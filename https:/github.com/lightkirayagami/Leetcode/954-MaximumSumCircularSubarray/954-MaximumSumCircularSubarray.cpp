// Last updated: 27/04/2026, 21:46:38
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum1 = sum(nums, n);
        int max_sum = kdmax(nums, n);
        int min_sum = kdmin(nums, n);

        int cs = sum1 - min_sum;

        if (max_sum > 0) {
            return max(max_sum, cs);
        }

        return max_sum;
    }

    int sum(vector<int>& nums, int n) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total = total + nums[i];
        }

        return total;
    }

    int kdmax(vector<int>& nums, int n) {
        int total_max = INT_MIN;
        int curr_sum = 0;

        for (int i = 0; i < n; i++) {
            curr_sum = curr_sum + nums[i];
            total_max = max(curr_sum, total_max);
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return total_max;
    }
    int kdmin(vector<int>& nums, int n) {
        int total_min = INT_MAX;
        int curr_sum = 0;

        for (int i = 0; i < n; i++) {
            curr_sum = curr_sum + nums[i];
            total_min = min(curr_sum, total_min);
            if (curr_sum > 0) {
                curr_sum = 0;
            }
        }
        return total_min;
    }
};