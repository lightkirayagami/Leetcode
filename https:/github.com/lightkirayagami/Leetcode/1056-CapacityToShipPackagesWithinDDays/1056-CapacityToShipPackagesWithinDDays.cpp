// Last updated: 27/04/2026, 21:46:14
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int n=weights.size();
        int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(ispossible(weights,mid,days))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
        
    }

    bool ispossible(vector<int>&weights,int mid,int days)
    {
        int currLoad=0;
        int daycount=1;

        int n=weights.size();
        for(int i=0;i<n;i++)
        {
            if(currLoad+weights[i]>mid)
            {
                daycount++;
                currLoad=0;
            }
            currLoad=currLoad+weights[i];
        }

        if(daycount<=days)
        {
            return true;
        }
        return false;


    }

};