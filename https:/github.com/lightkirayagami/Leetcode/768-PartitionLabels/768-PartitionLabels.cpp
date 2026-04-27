// Last updated: 27/04/2026, 21:47:13
class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }

        vector<int>ans;


        int maxreach=-1;
        int reach=0;
        for(int i=0;i<n;i++)
        {
            maxreach=max(mp[s[i]],maxreach);
            reach++;


            if(maxreach==i)
            {
                ans.push_back(reach);
                reach=0;
                
            }

            
        }

        return ans;
        
    }
};