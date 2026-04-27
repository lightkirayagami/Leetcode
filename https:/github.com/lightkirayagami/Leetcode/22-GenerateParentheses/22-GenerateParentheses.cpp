// Last updated: 27/04/2026, 21:52:57
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string>ans;

        solve(n,n,"",ans);
        return ans;
        
    }

    void solve(int openB,int closeB,string s,vector<string>&ans)
    {

        if(openB==0&&closeB>0)
        {
            while(closeB>0)
            {
                s=s+")";
                closeB--;
            }
        }
        if(openB==0&&closeB==0)
        {
            ans.push_back(s);
            return;
        }

        if(openB==closeB)
        {
            solve(openB-1,closeB,s+"(",ans);
        }
        else if(openB<closeB)
        {
            solve(openB-1,closeB,s+"(",ans);
            solve(openB,closeB-1,s+")",ans);
        }


    }
};