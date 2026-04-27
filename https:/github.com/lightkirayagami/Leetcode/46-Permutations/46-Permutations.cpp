// Last updated: 27/04/2026, 21:52:32
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>used(nums.size(),0);
        vector<int>path;
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

            used[i]=1;
            path.push_back(nums[i]);
            solve(nums,used,path,ans);
            path.pop_back();
            used[i]=0;
        }
        return;


    }
};