// Last updated: 27/04/2026, 21:46:25
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int >pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            neg.push_back(-(nums[i]));
            else
            pos.push_back(nums[i]);
        }
        reverse(neg.begin(),neg.end());
        int m=pos.size();
        int n=neg.size();

        int i=0;
        int j=0;
        int k=0;

        while(i<m&&j<n)
        {
            if(pos[i]<neg[j])
            {
                nums[k]=pos[i];
                i++;
            }
            else
            {
                nums[k]=neg[j];
                j++;
            }
            k++;
        }
        while(i<m)
        {
            nums[k]=pos[i];
            i++;
            k++;
        }
        while(j<n)
        {
            nums[k]=neg[j];
            j++;
            k++;
        }

        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        return nums;
        
    }
};