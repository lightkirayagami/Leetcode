// Last updated: 27/04/2026, 21:47:52
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>slide(26,0),freq(26,0);

        for(int i=0;i<s1.size();i++)
        {
            slide[s1[i]-'a']++;
        }
        int n=s2.size();
        int k=s1.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n)
        {
            freq[s2[j]-'a']++;
            if(j-i+1<k)
            {
                j++;
            }
             else if(j-i+1==k)
            {
                if(slide==freq)
                {
                    return true;
                }
                freq[s2[i]-'a']--;
                i++;
                j++;
            }
            
        }
        return false;
        
    }
};