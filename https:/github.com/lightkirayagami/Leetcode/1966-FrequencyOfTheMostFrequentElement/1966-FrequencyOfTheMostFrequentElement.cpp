// Last updated: 27/04/2026, 21:45:27
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int i=0;
        long long  cost=0;
        int ans=0;
        long long int sum=0;
        sort(nums.begin(),nums.end());
        for(int j=0;j<nums.size();j++)
        {
            sum=sum+nums[j];
            cost=(long long)nums[j]*(j-i+1)-sum;

            while(i<=j&&cost>k)
            {
                sum=sum-nums[i];
                cost=(long long)nums[j]*(j-i)-sum;
                i++;            
            }

            ans=max(ans,j-i+1);
        }

        return ans;
        
    }
};