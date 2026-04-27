// Last updated: 27/04/2026, 21:48:12
class Solution {
public:
    bool makesquare(vector<int>& match) {

        vector<int>sides(4,0);
        
        int sum=0;
        for(int i=0;i<match.size();i++)
        {
            sum=sum+match[i];
        }

        if(sum%4!=0)
        {
            return false;
        }
        sort(match.begin(),match.end(),greater<int>());

        int len=sum/4;

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
        }

        return ans;
    }
};