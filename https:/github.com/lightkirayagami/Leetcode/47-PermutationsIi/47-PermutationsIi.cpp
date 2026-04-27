// Last updated: 27/04/2026, 21:52:31
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<int>used(nums.size(),0);
        vector<int>path;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        solve(nums,used,path,ans);
        return ans;
        
    }

    void solve(vector<int>&nums,vector<int>&used,vector<int>&path,vector<vector<int>>&ans)
    {


        if(path.size()==nums.size())
        {
            ans.push_back(path);
        }


        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==1)
            {
                continue;
            }
            if (i>0&&nums[i]==nums[i-1]&&used[i-1]==0) continue;

            used[i]=1;
            path.push_back(nums[i]);
            solve(nums,used,path,ans);
            path.pop_back();
            used[i]=0;
        }
        return;


    }
        
    
};