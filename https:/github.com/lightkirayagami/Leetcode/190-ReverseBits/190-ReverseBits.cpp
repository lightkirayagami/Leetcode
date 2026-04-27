// Last updated: 27/04/2026, 21:50:14
class Solution {
public:
    int reverseBits(int n) {
        int x=0;
        for(int i=0;i<32;i++)
        {
            if((n & (1 << i)) != 0)
            {
                x=x|(1<<(31-i));
            }
        }


        return x;
        
        
    }
};