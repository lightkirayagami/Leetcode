// Last updated: 27/04/2026, 21:48:22
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> m1(26, 0), m2(26, 0);
        vector<int>ans;
        for(int i=0;i<p.size();i++)
        {
           m2[p[i] - 'a']++;
        }
        int i=0;
        int j=0;
        while(j<s.size())
        {
            m1[s[j]-'a']++;
            if(j-i+1<p.size())
            {
                j++;
            }
            else if(j-i+1==p.size())
            {
                if(m2==m1||m1==m2)
                {
                    ans.push_back(i);  
                }
                m1[s[i]-'a']--;
                    i++;
                    j++;
            }
        }

     return ans;   
    }
};