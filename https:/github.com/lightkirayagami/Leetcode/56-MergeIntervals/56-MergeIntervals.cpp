// Last updated: 27/04/2026, 21:52:21
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(ans.back()[1]>=nums[i][0])
            {
                int a=max(ans.back()[1],nums[i][1]);
                int b=min(ans.back()[0],nums[i][0]);

                ans.back()[0]=b;
                ans.back()[1]=a;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};