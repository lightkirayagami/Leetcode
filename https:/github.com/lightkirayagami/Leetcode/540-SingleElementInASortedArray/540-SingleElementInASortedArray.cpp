// Last updated: 27/04/2026, 21:47:59
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;
        if(nums.size()==1)
        {
            return nums[0];
        }

        while (l <= r) {
            int mid = (l + r) / 2;
            ans = nums[mid];

            if (mid == 0) {
                if (nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                } else {
                    l = mid + 1;
                }
            } else if (mid == nums.size() - 1) {
                if (nums[mid] != nums[mid - 1]) {
                    return nums[mid];
                } else {
                    r = mid - 1;
                }
            }
            else if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }

            else if (mid % 2 != 0) {
                if (nums[mid - 1] == nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            else {
                if (nums[mid] == nums[mid + 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};