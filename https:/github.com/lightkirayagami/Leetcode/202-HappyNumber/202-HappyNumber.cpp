// Last updated: 27/04/2026, 21:50:06
class Solution {
public:
    bool isHappy(int n) {

        while(n>=10)
        {
            long long ans=0;

            while(n!=0)
            {
                int last=n%10;
                n=n/10;
                ans = ans + last * last;
            }
            n=ans;
        }

        if(n==1||n==7)
        {
            return true;
        }

        return false;
        
    }
};