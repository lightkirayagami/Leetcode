// Last updated: 27/04/2026, 21:51:54
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int>path;
        solve(0,k,path,ans,nums);
        return ans;
        
    }

    void solve(int start,int k,vector<int>path,vector<vector<int>>&ans,vector<int>&nums)
    {

        if(k==0)
        {
            ans.push_back(path);
            return;
        }



        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            solve(i+1,k-1,path,ans,nums);
            path.pop_back();

        }


        
    }
};