// Last updated: 27/04/2026, 21:53:10
class Solution {
public:
    int maxArea(vector<int>& height) {


        int ans=0;

        int i=0;
        int n=height.size();
        int j=n-1;


        while(i<j)
        {
            int area=min(height[i],height[j])*(j-i);
            ans=max(area,ans);

            if(height[i]<=height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
        
    }
};