// Last updated: 27/04/2026, 21:52:50
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};