// Last updated: 27/04/2026, 21:52:26
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curr_max=0;
        int total=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            curr_max=curr_max+nums[i];
            total=max(curr_max,total);
            if(curr_max<0)
            {
                curr_max=0;
            }
        }
        return total;
        
    }
};