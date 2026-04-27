// Last updated: 27/04/2026, 21:53:13
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x = x / 10;
        }
          if (res < INT_MIN || res > INT_MAX) {
            return 0;
        } 
            else {
            return (int)res;
        }
        
    }
};