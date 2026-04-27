// Last updated: 27/04/2026, 21:47:37
class Solution {
public:
    bool validPalindrome(string s) {

        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }

            else
            {

                if(isplain(s,i+1,j)==true||isplain(s,i,j-1)==true)
                {
                    return true;
                }
                return false;
            }
        }

        return true;
        
    }

    bool isplain(string s,int i,int j)
    {
       while(i<=j)
       {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
       }
       return true;
    }
};