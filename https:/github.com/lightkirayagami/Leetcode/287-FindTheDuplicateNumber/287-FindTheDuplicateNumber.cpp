// Last updated: 27/04/2026, 21:49:15
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=0;
        int fast=0;
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
            {
                break;
            }
        }
        int slow1=0;
        while(true)
        {
            slow=nums[slow];
            slow1=nums[slow1];
            if(slow1==slow)
            {
                break;
            }
        }
        return slow1;;
        
    }
};