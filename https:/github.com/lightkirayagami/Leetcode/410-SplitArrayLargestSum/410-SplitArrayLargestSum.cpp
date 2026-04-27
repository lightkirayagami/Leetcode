// Last updated: 27/04/2026, 21:48:31
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int maxval=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxval)
            {
                maxval=max(maxval,nums[i]);
            }
        }

        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }

        int start=maxval;
        int end=sum;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(ispossible(nums,mid,k))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }

        return ans;
        
    }

    bool ispossible(vector<int>&nums,int mid,int k)
    {
        int currsum=0;
        int kval=1;
        int split=1;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(currsum+nums[i]>mid)
            {
                kval++;
                currsum=0;
            }
            currsum=currsum+nums[i];
        }

        if(kval<=k)
        {
            return true;
        }
        return false;
    }
};