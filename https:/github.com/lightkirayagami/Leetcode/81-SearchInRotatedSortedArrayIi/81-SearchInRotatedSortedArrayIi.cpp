// Last updated: 27/04/2026, 21:51:49
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=end+(start-end)/2;
            if(nums[mid]==target)
            {
                return true;
            }
             while(nums[mid]==nums[start]&&start<mid)
                {
                    start++;
                }
            if(nums[start]<=nums[mid])
            {
               
                if(target>=nums[start]&&target<nums[mid])
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            else
            {
                if(target>nums[mid]&&target<=nums[end])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return false;
    }
};