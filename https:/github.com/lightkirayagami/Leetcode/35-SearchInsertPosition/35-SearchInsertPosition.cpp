// Last updated: 27/04/2026, 21:52:43
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        cout<<start<<endl;
        cout<<end<<endl;
        return start;
        
    }
};