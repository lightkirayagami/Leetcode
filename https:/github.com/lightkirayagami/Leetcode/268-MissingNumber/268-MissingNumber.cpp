// Last updated: 27/04/2026, 21:49:21
class Solution {
public:
    int missingNumber(vector<int>& nums) {

       int x=nums.size();
       for(int i=0;i<nums.size();i++)
       {
            x=nums[i]^x;
            x=i^x;
       }
       return x;
        
    }
};