// Last updated: 27/04/2026, 21:45:06
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1000000;
        int i=0;
        int j=0;
        while(j<n)
    {
        if(j-i+1<k)
        {
            j++;
        }
        else if (j-i+1==k)
        {
            ans=min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }
    }
    return ans;
        
    }
};