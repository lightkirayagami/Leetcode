// Last updated: 27/04/2026, 21:45:43
class Solution {
public:
    bool hasAllCodes(string s, int k) {

        set<string>st;
        int i=0;
        int j=0;
        string ans="";
        while(j<s.size())
        {
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                string s1=s.substr(i,k);
                if(st.find(s1)==st.end())
                {
                    st.insert(s1);
                }
                i++;
                j++;
            }
        }

      if(st.size()==pow(2,k))
      {
        return true;
      }
        return false;
        
    }
};