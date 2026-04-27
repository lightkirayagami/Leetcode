// Last updated: 27/04/2026, 21:49:01
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        long temp = 3;
        while(temp <= n)
        {
            if(temp == n) return true;
            temp *= 3;
        }
        return false;
    }
        
    
};