// Last updated: 27/04/2026, 21:50:02
class Solution {
public:
    bool isIsomorphic(string s, string t) {
            bool a=isiso(s,t);
            bool b=isiso(t,s);
            return a&b;
        }
    bool isiso(string s, string t)
    {
           map<char,char>m;
        for(int i=0;i<s.size();i++)
        {
            auto it = m.find(s[i]);
            if(it!=m.end())
            {    
                  if(it->second!=t[i])
                    return false;
            }
            else
            {
                m.insert({s[i],t[i]});

            }
    }

       return true;

        
    }
};