// Last updated: 27/04/2026, 21:52:52
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[j])
            {
               j++;
               nums[j]=nums[i];
            }
        }
        
   return j+1;
    }
};