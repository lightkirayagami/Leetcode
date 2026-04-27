// Last updated: 27/04/2026, 21:48:40
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            char a=s[i];
            m[a]++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            char a=s[i];
            auto it=m.find(a);
            if(it->second==1)
            {
                return i;
            }
        }
        return -1;
        
    }
};