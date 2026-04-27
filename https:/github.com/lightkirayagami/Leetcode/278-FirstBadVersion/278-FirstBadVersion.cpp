// Last updated: 27/04/2026, 21:49:20
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        
        int start=0;
        int end=n;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(isBadVersion(mid)==false)
            {
                start=mid+1;
               
            }
            else
            {
                 ans=mid;
                end=mid-1;
            }
        }
        return ans;
        
        
    }
};