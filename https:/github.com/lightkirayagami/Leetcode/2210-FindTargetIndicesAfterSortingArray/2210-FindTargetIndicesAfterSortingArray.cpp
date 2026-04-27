// Last updated: 27/04/2026, 21:44:58
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         vector<int>ansfinal;
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int ans=firstposi(start,end,nums,target);
        int ans1=lastposi(start,end,nums,target);
        if(ans==-1||ans1==-1)
	    {
	        return ansfinal;
	    }
        for(int i=ans;i<=ans1;i++)
        {
            ansfinal.push_back(i);
        }
        
        return ansfinal;
        
    }
    int firstposi(int start,int end,vector<int>& nums,int target)
    {
        int ans=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    };
    int lastposi(int start,int end,vector<int>& nums,int target)
    {
        int ans=-1;
       
        while(start<=end)
        {
             int mid=start+(end-start)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
        
    }
};