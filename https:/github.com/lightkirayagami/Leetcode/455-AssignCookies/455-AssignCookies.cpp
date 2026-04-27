// Last updated: 27/04/2026, 21:48:15
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());


        int i=0;
        int j=0;
        int m=g.size();
        int n=s.size();
        int ans=0;

        while(i<m&&j<n)
        {
            if(g[i]<=s[j])
            {
                ans++;
                i++;
                j++;
            }
        
            else
            {
                j++;
            }
        }

        // return ans;


        // map<int,int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     mp[s[i]]++;
        // }


        // for(int i=0;i<m;i++)
        // {
        //     if(mp.find(g[i])!=mp.end()&&mp[g[i]]>0)
        //     {
        //         ans++;
        //         mp[g[i]]--;
        //         if(mp[g[i]]==0)
        //         {
        //             mp.erase(g[i]);
        //         }
        //     }
        // }

        return ans;

    }
};