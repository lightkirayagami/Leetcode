// Last updated: 27/04/2026, 21:48:47
class Solution {
public:
    bool isPerfectSquare(int num) {

        int start=1;
        int end=num;

        while(start<=end)
        {
            long mid=(start)+(end-start)/2;
            long ans=mid*mid;
            if(ans==num)
            {
                return true;
            }
            else if(ans<num)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
        
    }
};