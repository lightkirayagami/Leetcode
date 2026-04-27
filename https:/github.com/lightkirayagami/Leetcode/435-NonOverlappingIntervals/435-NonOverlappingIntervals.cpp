// Last updated: 27/04/2026, 21:48:23
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;


        ans.push_back(nums[0]);

        int overlap=0;
        for(int i=1;i<nums.size();i++)
        {
            if(ans[ans.size()-1][1]>nums[i][0])
            {
                overlap++;
                int a=min(ans[ans.size()-1][1],nums[i][1]);
                ans[ans.size()-1][1]=a;

            }
            else
            {
                ans.push_back(nums[i]);
            }
        }

        return overlap;
        
    }
};