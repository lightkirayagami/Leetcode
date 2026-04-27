// Last updated: 27/04/2026, 21:45:00
class Solution {
public:
    int maxDistance(vector<int>& nums) {

        int i=0;
        int j=nums.size()-1;
        int ans1=0;


        while(i<j)
        {
            if(nums[i]==nums[j])
            {
                j--;
            }
            else
            {
                ans1=j-i;
                break;
            }
        }
        i=0;
        j=nums.size()-1;
        int ans2=0;

        while(i<=j)
        {
            if(nums[i]==nums[j])
            {
                i++;
            }
            else
            {
                ans2=j-i;
                break;
            }
        }



        return max(ans1,ans2);




        
    }
};