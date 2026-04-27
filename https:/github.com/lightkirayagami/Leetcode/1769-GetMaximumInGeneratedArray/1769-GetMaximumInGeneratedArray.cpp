// Last updated: 27/04/2026, 21:45:33
class Solution {
public:
    int getMaximumGenerated(int n) {
        int i;
        
      int nums[n+1];
        int max=-1;

        if(n==0)
        {
           return 0; 
            
        }
        else if(n==1)
        {
            return 1;
        }
        
        else
        {
            nums[0]=0;
           nums[1]=1;
            for(i=2;i<n+1;i++)
            {
                if(i%2==0)
                {
                    nums[i]=nums[i/2];
                    
                }
                else
                {
                    
                    nums[i]=nums[i/2]+nums[i/2+1];
                }
            }
            
         }
        for(i=0;i<n+1;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
            }
        }
        return max;
        
        
        
        
      
        
    }
};