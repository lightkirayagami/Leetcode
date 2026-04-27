// Last updated: 27/04/2026, 21:52:45
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int ans1=-1;
        int ans2=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans1=mid;
                end=mid-1;
            }
            else if(target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        start=0;
        end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans2=mid;
                start=mid+1;
            }
            else if(target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    vector<int>ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
        
    }
};