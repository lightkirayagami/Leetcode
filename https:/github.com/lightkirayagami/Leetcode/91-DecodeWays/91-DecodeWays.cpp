// Last updated: 27/04/2026, 21:51:38
class Solution {
public:
    int numDecodings(string s) {

        int ans=0;
        vector<int>dp(s.size()+1,-1);
        ans=solve(s,0,dp);
        
        return ans;
        
    }

    int solve(string &s,int i,vector<int>&dp)
    {
        if(i==s.size())
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }


        int one=solve(s,i+1,dp);
        int two=0;

        if(s.substr(i,2)<"27"&&i<s.size()-1)
        {
            two=solve(s,i+2,dp);
        }
        dp[i]=one+two;

        return one+two;
    }


};