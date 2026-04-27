// Last updated: 27/04/2026, 21:45:25
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int ele = nums1[i];
            int bsindex = bs(ele, nums2);
            if (bsindex == -1 || bsindex < i) {
                continue;
            }
            ans = max(ans, bsindex - i);
        }

        return ans;

        
    }
   int bs(int target, vector<int>& nums) {
    int ans = -1;
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            start = mid + 1;   // go right
        } else {
            end = mid - 1;     // go left
        }
    }

    return ans;
}
};