// Last updated: 27/04/2026, 21:47:30
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& match, int k) {
        vector<int>sides(k,0);
        
        int sum=0;
        for(int i=0;i<match.size();i++)
        {
            sum=sum+match[i];
        }

        if(sum%k!=0)
        {
            return false;
        }
        sort(match.begin(),match.end(),greater<int>());

        int len=sum/k;

        bool ans=false;

        ans=solve(match,len,sides,0);
        return ans;
        
        
    }
     bool solve(vector<int>& match,int len,vector<int>&sides,int start)
    {

        if(start==match.size())
        {
            return true;
        }



        bool ans=false;

        for(int i=0;i<sides.size();i++)
        {
            if(sides[i]+match[start]<=len)
            {
                sides[i]=sides[i]+match[start];
                ans=ans||solve(match,len,sides,start+1);
                sides[i]=sides[i]-match[start];
            }
            if(sides[i] == 0) break;
        }

        return ans;
    }
};