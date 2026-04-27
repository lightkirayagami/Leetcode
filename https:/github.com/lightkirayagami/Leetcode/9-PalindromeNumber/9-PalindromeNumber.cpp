// Last updated: 27/04/2026, 21:53:11
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }

        int rev=reverse(x);
        if(rev==x)
        {
            return true;
        }
        return false;        
    }


    int reverse(int n)
    {
        int ans=0;
        while(n>0)
        {
            int last=n%10;
            n=n/10;
            ans=(long long)ans*10+last;
        }

        return ans;



    }
};