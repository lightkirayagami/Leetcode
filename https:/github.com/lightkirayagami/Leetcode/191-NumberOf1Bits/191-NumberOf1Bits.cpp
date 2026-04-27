// Last updated: 27/04/2026, 21:50:13
class Solution {
public:
    int hammingWeight(int n) {

        int count=0;
        while(n!=0)
        {
            n=n&(n-1);
            count++;
        }
        return count;
        
    }
};