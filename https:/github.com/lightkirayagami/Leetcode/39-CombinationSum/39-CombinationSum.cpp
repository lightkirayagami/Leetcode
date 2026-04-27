// Last updated: 27/04/2026, 21:52:38
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int>path;
        vector<vector<int>>ans;
        solve(0,path,ans,target,nums);
        return ans;
        
    }

    void solve(int x,vector<int>&path,vector<vector<int>>&ans,int target,vector<int>&nums)
    {
        if(target<0)
        {
            return;
        }

        if(target==0)
        {
            ans.push_back(path);
            return;
        }

        for(int i=x;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            solve(i,path,ans,target-nums[i],nums);
            path.pop_back();
        }
        return;
    }
};