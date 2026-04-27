// Last updated: 27/04/2026, 21:51:41
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=0;i<n;i++)
       {
        nums1.pop_back();
       }
        vector<int>ans(m+n,0);
        int i=0;
        int j=0;
        int k=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<=nums2[j])
            {
                ans[k]=nums1[i];
                k++;
                i++;
            }
            else
            {
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<nums1.size())
        {
            ans[k]=nums1[i];
            i++;
            k++;
        }
        while(j<nums2.size())
        {
            ans[k]=nums2[j];
            j++;
            k++;
        }
        // for(int i=0;i<nums1.size();i++)
        // {
        //     nums1[i]=ans[i];
        // }
        int l=0;
        for(int i=0;i<m;i++)
        {
            nums1[i]=ans[i];
            l++;
        }
       
         for(int i=0;i<n;i++)
        {
            nums1.push_back(ans[l]);
            l++;
        }

        for(int i=0;i<m+n;i++)
        {
            cout<<ans[i]<<" ";
        }
        
    }
};