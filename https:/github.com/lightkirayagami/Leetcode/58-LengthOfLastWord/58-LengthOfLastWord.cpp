// Last updated: 27/04/2026, 21:52:18
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int j=n-1;
        if(n==1&&s[0]!=' ')
        {
            return 1;
        }
        else if(n==1)
        {
            return 0;
        }

        while(j>0&&s[j]==' ')
        {
            j--;
        }
        int count=0;
        while(j>=0&&s[j]!=' ')
        {
            count++;
            j--;
        }
       
        
     return count;
    }
};