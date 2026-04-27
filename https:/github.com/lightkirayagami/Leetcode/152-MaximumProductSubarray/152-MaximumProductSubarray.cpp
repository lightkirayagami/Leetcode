// Last updated: 27/04/2026, 21:50:31
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxsofar=nums[0];
        int minsofar=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(minsofar,maxsofar);
            }

            minsofar=min(minsofar*nums[i],nums[i]);
            maxsofar=max(maxsofar*nums[i],nums[i]);
            ans=max(maxsofar,ans);
        }
        return ans;
        
    }
};