// Last updated: 27/04/2026, 21:53:16
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m=nums1.size();
        int n=nums2.size();

        int idx1=0;
        int idx2=0;
        int value1=0;
        int value2=0;

        int i=0;
        int j=0;
        int k=0;

        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                if(k==((m+n)/2)-1)
                {
                    value1=nums1[i];
                }
                if(k==(m+n)/2)
                {
                    value2=nums1[i];
                }
                i++;
                k++;
                
                
            }
            else
            {
                if(k==((m+n)/2)-1)
                {
                    value1=nums2[j];
                }
                if(k==(m+n)/2)
                {
                    value2=nums2[j];
                }
                j++;
                k++;
            }
        }

        while(i<m)
        {
            if(k==((m+n)/2)-1)
                {
                    value1=nums1[i];
                }
                if(k==(m+n)/2)
                {
                    value2=nums1[i];
                }
                i++;
                k++;
        }
        while(j<n)
        {
             if(k==((m+n)/2)-1)
                {
                    value1=nums2[j];
                }
                if(k==(m+n)/2)
                {
                    value2=nums2[j];
                }
                j++;
                k++;
        }


        if((m+n)%2==0)
        {
            return (value1+value2)/2.0;
        }
        else
        {
            return value2;
        }


        return -1;

        
    }
};