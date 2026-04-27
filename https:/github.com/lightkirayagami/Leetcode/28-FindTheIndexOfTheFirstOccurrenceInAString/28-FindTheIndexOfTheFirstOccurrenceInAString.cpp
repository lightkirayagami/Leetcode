// Last updated: 27/04/2026, 21:52:49
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int k=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {  
           
            if(haystack[i]==needle[k])
            {   
                k++;
            }
            else
            {
                i=i-k;
                k=0;
            }
            if(k==m)
            {
                ans=i-k+1;
                return ans;
            }
        }
        return -1;

        
    }
};