// Last updated: 27/04/2026, 21:45:09
class Solution {
public:
    int minSwaps(string s) {
        int max1=0;
        int closing=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                closing--;
            }
            else if(s[i]==']')
            {
                closing++;
            }
            max1=max(closing,max1);
        }
        if(max1%2==0)
        {
            return max1/2; 
        }
        else
        return (max1+1)/2;
        
    }
};