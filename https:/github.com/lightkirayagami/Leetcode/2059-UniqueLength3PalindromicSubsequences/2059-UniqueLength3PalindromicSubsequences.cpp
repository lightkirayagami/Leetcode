// Last updated: 27/04/2026, 21:45:11
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
      unordered_set<char>st;
      for(int i=0;i<n;i++)
      {
        st.insert(s[i]);
      }
    int ans=0;
      for(char letter: st)
      {
        int first=-1;
        int last=-1;

        for(int i=0;i<n;i++)
        {
            if(s[i]==letter) 
            {
                if(first==-1)
                {
                    first=i;
                }
                last=i;
            }
        }
        unordered_set<char>sts;
        for(int i=first+1;i<=last-1;i++)
        {
            sts.insert(s[i]);
        }
        ans=ans+sts.size();
      }
      return ans;
    }
};