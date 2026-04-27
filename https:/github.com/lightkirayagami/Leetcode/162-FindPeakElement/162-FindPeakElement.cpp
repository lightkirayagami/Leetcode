// Last updated: 27/04/2026, 21:50:25
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int start=0;
        int end=nums.size()-1;
        int ans=0;

        while(start<end)
        {
            int mid=(start+end)/2;

            if(nums[mid]<nums[mid+1])//incresing slope
            {
                start=mid+1;
            }
            else
            {
               
                end=mid;
            }

            
        }
        return end;
        
    }


    // nums[mid-1]<nums[mid]<nums[mid+1];
    // nums[mid-1]>nums[mid]>nums[mid+1]
};