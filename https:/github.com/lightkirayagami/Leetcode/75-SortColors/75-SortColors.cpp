// Last updated: 27/04/2026, 21:51:57
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,m=0;
        int e=nums.size()-1;

        while(m<=e)
        {
            if(nums[m]==1)
            {
                m++;
            }
            else if(nums[m]==0)
            {
                swap(nums[s],nums[m]);
                s++;
                m++;
            }
            else
            {
                swap(nums[e],nums[m]);//but when we swap from right it can have both 0 or 1 coming from right and if 0 comes we need to check again as it has to go left so we dont increment m
            
                e--;
            }

        }
        
    }
};