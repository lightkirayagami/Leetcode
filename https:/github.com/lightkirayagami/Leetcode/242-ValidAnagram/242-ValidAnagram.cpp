// Last updated: 27/04/2026, 21:49:26
class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int>alp(26,0);

        for(int i=0;i<s.size();i++)
        {
            alp[s[i]-97]++;
        }


        for(int i=0;i<t.size();i++)
        {
            alp[t[i]-97]--;
        }


        for(int i=0;i<26;i++)
        {
            if(alp[i]!=0)
            {
                return false;
            }
        }

        return true;

        
        
    }
};