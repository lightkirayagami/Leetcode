// Last updated: 27/04/2026, 21:48:33
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>chL(26,0);
        vector<int>chU(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                chL[s[i]-'a']++;
            }
            else
            {
                chU[s[i]-'A']++;
            }
        }

        int ans=0;

        for(int i=0;i<chL.size();i++)
        {
            if(chL[i]>0&&chL[i]%2==0)
            {
                ans=ans+chL[i];
                chL[i]=0;
            }

            else if(chL[i]>1&&chL[i]%2==1)
            {
                ans=ans+(chL[i]/2)*2;
                chL[i]=chL[i]%2;
            }
        }


        for(int i=0;i<chU.size();i++)
        {
            if(chU[i]>0&&chU[i]%2==0)
            {
                ans=ans+chU[i];
                chU[i]=0;
            }

            else if(chU[i]>1&&chU[i]%2==1)
            {
                ans=ans+(chU[i]/2)*2;
                chU[i]=chU[i]%2;
            }
        }

        for(int i=0;i<chL.size();i++)
        {
            if(chL[i]==1||chU[i]==1)
            {
                ans=ans+1;
                break;
            }
        }
        return ans;

        
    }
};