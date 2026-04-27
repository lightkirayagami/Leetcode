// Last updated: 27/04/2026, 21:44:37
class Solution {
public:
    int mirrorDistance(int n) {
        
        int rev=reverse(n);
        return abs(rev-n);
    }

    int reverse(int n)
    {
        int num=0;
        while(n>0)
        {
            int last=n%10;
            n=n/10;
            num=num*10+last;
        }

        return num;
    }
};