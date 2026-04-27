// Last updated: 27/04/2026, 21:45:38
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
     map<int,int>nums;
        // for(int i=0;i<k+1;i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        int n=arr.size();
       for(int i=0;i<n;i++)
       {
           int a=((arr[i]%k)+k)%k;
           nums[a]++;
       }
        
        if(nums[0]%2!=0)
        {
            return false;
        }
        for(int i=1;i<k;i++)
        {
            if(nums[i]!=nums[k-i])
            {
                return false;
            }
        }
        return true;
    }
};