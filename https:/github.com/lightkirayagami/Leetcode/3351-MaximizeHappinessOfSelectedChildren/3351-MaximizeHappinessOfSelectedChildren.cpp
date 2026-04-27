// Last updated: 27/04/2026, 21:44:40
class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());


        long long int ans=0;
        int negative=0;
        for(int i=0;i<k;i++)
        {
            if(nums[i]-negative<=0)
            {
                break;
            }
            ans=ans+nums[i]-negative;
            negative++;

    
        }
        return ans;
        
    }
};