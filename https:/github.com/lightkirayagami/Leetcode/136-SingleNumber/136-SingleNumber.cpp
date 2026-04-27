// Last updated: 27/04/2026, 21:50:48
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int x=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            x=x^nums[i];
        }
        return x;
        
    }
};