// Last updated: 27/04/2026, 21:52:10
class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {

        int x=0;
        int carry=0;
        int n=nums.size()-1;
        nums[n]=nums[n]+1;

        if(nums[n]==10)
        {
            carry=1;
            nums[n]=0;
        }
        else
        {
            return nums;
        }



        for(int i=n-1;i>=0;i--)
        {

            int total=nums[i]+carry;
            if(total==10)
            {
                nums[i]=0;
                carry=1;
            }
            else
            {
                nums[i]=total;
                carry=0;
            }
            

        }
        vector<int>ans;
        if(carry==1)
        {
            ans.push_back(1);
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(nums[i]);
            }
            return ans;
        }
        return nums;
        
    }
};