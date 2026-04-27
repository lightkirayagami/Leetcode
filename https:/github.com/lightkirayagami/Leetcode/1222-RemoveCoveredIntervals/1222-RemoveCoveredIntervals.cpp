// Last updated: 27/04/2026, 21:46:06
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {


        sort(nums.begin(),nums.end(),[](auto &a,auto&b)
        {
            if(a[0]==b[0])
            {
                return a[1]>b[1];
            }
            return a[0]<b[0];

        });

        int counter=0;
        int prev=0;

        for(auto it:nums)
        {
            if(it[1]<=prev)
            {
                counter++;
            }
            else
            {
                prev=it[1];
            }
        }

        return nums.size()-counter;


        
    }
};