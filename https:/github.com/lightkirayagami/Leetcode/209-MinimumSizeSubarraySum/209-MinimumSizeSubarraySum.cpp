// Last updated: 27/04/2026, 21:49:55
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0;
        int j=0;
        long int sum=0;
        while(j<nums.size())
        {
            sum=sum+nums[j];
            if(sum<target)
            {
                j++;
            }
            else if(sum==target)
            {
                ans=min(ans,j-i+1);
                j++;
            }
            else if(sum>target)
            {
                while(sum>=target)
                {
                    ans=min(ans,j-i+1);
                    sum=sum-nums[i];
                    i++;
                }
                
               j++;
                
            }
        }
        return (ans == INT_MAX) ? 0 : ans;

        
    }
};