// Last updated: 27/04/2026, 21:52:35
class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        vector<int>leftmax(n,-1);
        vector<int>rightmax(n,-1);

        int minNum=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(height[i]>minNum)
            {
                minNum=height[i];
               
            }
             leftmax[i]=minNum;
        }

        minNum=INT_MIN;

        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>minNum)
            {
                 minNum=height[i];
            }

            rightmax[i]=minNum;
        }


        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+(min(leftmax[i],rightmax[i])-height[i]);
        }
        return ans;
    
    }
};