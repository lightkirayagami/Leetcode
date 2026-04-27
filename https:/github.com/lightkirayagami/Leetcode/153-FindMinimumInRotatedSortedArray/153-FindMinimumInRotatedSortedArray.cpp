// Last updated: 27/04/2026, 21:50:30
class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        int ans = INT_MAX;

        while(start <= end)
        {
            int mid = (start + end) / 2;

            // Case 1: right side has pivot → go right
            if(nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                // mid could be the answer
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }
};