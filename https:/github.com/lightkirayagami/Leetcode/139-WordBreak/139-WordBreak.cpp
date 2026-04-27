// Last updated: 27/04/2026, 21:50:45
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> mp;
        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]]++;
        }

        vector<int>dp(s.size()+1,-1);

        bool ans = false;

        ans = solve(wordDict, s, 0, mp,dp);
        return ans;
    }

    bool solve(vector<string>& wordDict,string s,int curr,unordered_map<string, int> &mp,vector<int>&dp)
    {
        if(curr==s.size())
        {
            return true;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        bool ans=false;

        for(int i=1;i<=s.size()-curr;i++)
        {
            string s1=s.substr(curr,i);
            if(mp.find(s1)!=mp.end())
            {
                ans=ans||solve(wordDict,s,curr+i,mp,dp);
            }
        }
        dp[curr]=ans;

        return ans;



    }
};

// abcd
// 0123

// curr=1;
// s.size()=4
// 4-1 3
// 1,2,3

// curr 0;
// s.size()-curr=4
// 1,2,3,4

// curr=3;
// 4-3=1


        // // string s1="";
        // // while(mp.find(s1)==mp.end()&&i<s.size())
        // // {
        // //     s1=s1+s[i];
        // //     i++;
        // // }
        // // if(i==s.size())
        // // {
        // //     return false;
        // // }

        // bool a=solve(wordDict,s,i,mp);

        // for(int i=1;i<s.size())
        // return a;