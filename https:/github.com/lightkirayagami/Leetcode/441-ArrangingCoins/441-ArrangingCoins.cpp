// Last updated: 27/04/2026, 21:48:20
class Solution {
public:
    int arrangeCoins(int n) {
        int start=0;
        int end=n;
        int ans=0;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
             long long ineq = (static_cast<long long>(mid) * (mid + 1)) / 2;

            if(ineq>n)
            {
                end=mid-1;
            }
            else
            {
                ans=mid;
                start=mid+1;
            }
            
        }
        return ans;
        
    }
};