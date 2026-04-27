// Last updated: 27/04/2026, 21:51:52
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,temp,ans,nums);
        return ans;
        
    }

    void solve(int x,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums)
    {
        ans.push_back(temp);

        for(int i=x;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(i+1,temp,ans,nums);
            temp.pop_back();
        }
        return;
    }
};