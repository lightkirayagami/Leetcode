// Last updated: 27/04/2026, 21:47:26
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>lsum;
        vector<int>rsum;

        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            lsum.push_back(l);
            l=l+nums[i];
            
            
        }
        int r=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            rsum.push_back(r);
            r=r+nums[i];
        }

        reverse(rsum.begin(),rsum.end());
        for(int i=0;i<nums.size();i++)
        {
            if(lsum[i]==rsum[i])
            
            {
                return i;
            }
        }
    //      for(int i=0;i<lsum.size();i++)
    //     {
    //         cout<<lsum[i]<<" ";
    //     }

    //    cout<<endl;
    //     for(int i=0;i<lsum.size();i++)
    //     {
    //         cout<<rsum[i]<<" ";
    //     }
       
        
        return -1;
    }
};