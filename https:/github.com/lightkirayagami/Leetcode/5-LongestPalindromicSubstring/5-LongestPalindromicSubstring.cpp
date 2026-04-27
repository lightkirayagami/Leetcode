// Last updated: 27/04/2026, 21:53:14
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int max_len=0;
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=i+diff;j<n;i++,j++)
            {
                if(diff==0)
                {
                    dp[i][j]=1;
                }
                else if(diff==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=2;
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1]>0)
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j]!=0)
                {
                    if(j-i+1>max_len)
                    {
                        max_len=j-i+1;
                        ans=s.substr(i,max_len);
                    }

                }
            }
        }
        return ans;
        
    }
};