// Last updated: 27/04/2026, 21:44:57
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int max=INT_MIN;
        int min=INT_MAX;
        int minposi=0,maxposi=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(min>nums[i])
            {
                min=nums[i];
                minposi=i;
            }
            if(max<nums[i])
            {
                max=nums[i];
                maxposi=i;
                
            }
        }
        int a=0,b=0,c=0,d=0;
        
        a=std::max(minposi+1,maxposi+1);
        b=std::max(n-minposi,n-maxposi);
        c=(minposi+1)+(n-maxposi);
        d=(maxposi+1)+(n-minposi);
        
       
        return std::min({a,b,c,d});
        
    }
};