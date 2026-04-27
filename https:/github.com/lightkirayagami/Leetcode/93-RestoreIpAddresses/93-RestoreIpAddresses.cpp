// Last updated: 27/04/2026, 21:51:35
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string s1="";
        solve(0,ans,s1,s,0);
        return ans;
        
    }

    void solve(int start,vector<string>&ans,string &path,string &s,int parts)
    {
    if (start == s.size() && parts == 4)
    {   cout<<path[s.size()-1];
        ans.push_back(path);
        return; 
    }
    if (start == s.size() || parts == 4) 
    {
        return ;
    }
     
    

    for(int i=1;i<=3;i++)
    {
       
        if(i+start>s.size())
        {
            break;
        }
         string str=s.substr(start,i);
         int size=str.size();
       

        if(str[0]=='0' and i>1)
        {
            continue;
        }
        if(stoi(str)>255)
        {
            continue;
        }
        if(parts<3)
        {
        path=path+str+'.';
        size++;

        }
        else
        {
            path=path+str;
        }

       
        solve(start+i,ans,path,s,parts+1);
        for(int j=0;j<size;j++)
        {
            path.pop_back();
        }

    }


    

    }
};