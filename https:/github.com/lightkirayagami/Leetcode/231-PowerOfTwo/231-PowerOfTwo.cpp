// Last updated: 27/04/2026, 21:49:38
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return 0;
        }
       
       long double a=log2(n);
        long int b=(long int)a;
            if(b==a)
            {
                return 1;
            }
        return 0;
        
    }
};