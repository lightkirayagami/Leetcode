// Last updated: 27/04/2026, 21:47:42
class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=diff;j<s.size();i++,j++)
            {
                if(diff==0)
                {
                    dp[i][j]=true;
                }
                else if(diff==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }

                if(dp[i][j])
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};