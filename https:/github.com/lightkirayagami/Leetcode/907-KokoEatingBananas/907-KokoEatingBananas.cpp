// Last updated: 27/04/2026, 21:46:48
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int start=1;
        int n=piles.size();
        int end=piles[n-1];
        int ans=0;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(ispossible(mid,piles,h))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<3/4;
    cout<<3%4;
    return ans;
        
    }

    bool ispossible(int mid,vector<int>&piles,int h)
    {
       long long int totaltime=0;

        for(int i=0;i<piles.size();i++)
        {
            totaltime=totaltime+piles[i]/mid;

            if(piles[i]%mid>0)
            {
                totaltime++;
            }
        
        }
        if(totaltime<=h)
        {
            return true;
        }
        return false;




    }
};