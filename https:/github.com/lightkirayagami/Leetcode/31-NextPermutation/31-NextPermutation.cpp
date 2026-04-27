// Last updated: 27/04/2026, 21:52:48
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
       int idx1=-1, idx2=-1;
        for(int i=n;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                idx1=i-1;
                break;
            }
        }
        if(idx1==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
        for(int i=n;i>=0;i--)
        {
            if(nums[i]>nums[idx1])
            {
                idx2=i;
                break;
            }
        }
             // cout<<idx1<<" "<<idx2<<endl;
            swap(nums[idx1],nums[idx2]);
            sort(nums.begin()+idx1+1,nums.end());
        }
        
    }
};