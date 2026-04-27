// Last updated: 27/04/2026, 21:48:25
class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxfreq=0;
        unordered_map<char,int>mp;
        int ans=0;
        int i=0;


        for(int j=0;j<s.size();j++)
        {
            mp[s[j]]++;

            if(mp[s[j]]>maxfreq)
            {
                maxfreq=mp[s[j]];


            }

            while(((j-i+1)-maxfreq)>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            ans=max(ans,j-i+1);
        }

        return ans;
        
    }
};