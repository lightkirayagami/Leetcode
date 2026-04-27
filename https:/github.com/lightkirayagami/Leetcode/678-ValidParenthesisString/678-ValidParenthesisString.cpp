// Last updated: 27/04/2026, 21:47:39
class Solution {
public:
    bool checkValidString(string s) {

        vector<vector<int>>dp(s.size()+1,vector<int>(101,-1));
        return solve(s,0,0,0,dp);
        
    }

    bool solve(string s,int i,int open,int close,vector<vector<int>>&dp)
    {
        int balance=open-close;
        if(balance<0)
        {
            return false;
        }

        if(i==s.size()&&open==close)
        {
            return true;
        }
        if(i==s.size()&&open!=close)
        {
            return false;
        }
        if(dp[i][balance]!=-1)
        {
            return dp[i][balance];
        }
        int ans=false;


        if(s[i]=='(')
        {
            ans=ans||solve(s,i+1,open+1,close,dp);
        }
        else if(s[i]==')')
        {
            ans=ans||solve(s,i+1,open,close+1,dp);
        }
        else
        {
            ans=ans||solve(s,i+1,open+1,close,dp);
            ans=ans||solve(s,i+1,open,close+1,dp);
            ans=ans||solve(s,i+1,open,close,dp);
        }
        dp[i][balance]=ans;

        return ans;
    }
};