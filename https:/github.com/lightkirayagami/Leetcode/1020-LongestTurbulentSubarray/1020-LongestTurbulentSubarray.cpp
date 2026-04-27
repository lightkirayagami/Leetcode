// Last updated: 27/04/2026, 21:46:24
class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {

        int n=nums.size();

        int maxlen=1;
        int len=1;
        string sign="?";

        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                if(sign=="?"||sign=="<")
                {
                    len++;
                    maxlen=max(len,maxlen);
                    sign=">";
                }
                else
                {
                    len=2;
                    maxlen=max(len,maxlen);
                    sign=">";
                }
            }
            else if(nums[i]<nums[i-1])
            {
                if(sign=="?"||sign==">")
                {
                    len++;
                    maxlen=max(len,maxlen);
                    sign="<";
                }
                else
                {
                    len=2;
                    maxlen=max(len,maxlen);
                    sign="<";
                }
            }
            else
            {
                len=1;
                maxlen=max(len,maxlen);
                sign="?";
                
            }
        }
        return maxlen;

        
    }
};