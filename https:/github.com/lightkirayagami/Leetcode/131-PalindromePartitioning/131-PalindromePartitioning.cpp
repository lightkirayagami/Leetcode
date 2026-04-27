// Last updated: 27/04/2026, 21:50:52
class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>path;

        solve(s,ans,0,path);
        return ans;
        
    }


    void solve(string s,vector<vector<string>>&ans,int start,vector<string>&path)
    {
        if(start>=s.size())
        {
            ans.push_back(path);
            return;
        }


        for(int i=start;i<s.size();i++)
        {
            string str=s.substr(start,i-start+1);
            if(ispalindronme(str)==true)
            {
                path.push_back(str);
                solve(s,ans,i+1,path);
                path.pop_back();

            }

        
        }
    }

    bool ispalindronme(string str)
    {

        string s1=str;
        string s2=str;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};