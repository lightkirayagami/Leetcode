// Last updated: 27/04/2026, 21:45:18
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ans=0;
        // string s1=s;

        // for(int i=0;i<removable.size();i++)
        // {
        //     s1[removable[i]]='0';
        //     if(istrue(s1,p)==true)
        //     {
        //         ans++;
        //         continue;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // return ans;

        int start=0;
        int end=removable.size()-1;
        // int ans=0;
        // string s1=s;
        while(start<=end)
        {
            string s1=s;
            int mid=start+(end-start)/2;
            for(int i=0;i<=mid;i++)
            {
                s1[removable[i]]='0';
            }

            if(istrue(s1,p)==true)
            {
                ans=max(ans,mid+1);
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }

        }
        return ans;   
    }

    bool istrue(string s,string p)
    {
        int i=0;
        int j=0;
        int m=s.size();
        int n=p.size();
        while(i<m&&j<n)
        {
            if(s[i]==p[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(j==n)
        {
            return true;
        }
        return false;
    }
};