// Last updated: 27/04/2026, 21:51:39
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>path;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        solve(0,nums,path,ans,st);
        return ans;
        
    }

    void solve(int start,vector<int>&nums,vector<int>path,vector<vector<int>>&ans,set<vector<int>>&st)
    {
        
            // st.insert(path);
        ans.push_back(path);
        


        for(int i=start;i<nums.size();i++)
        {
             if (i > start && nums[i] == nums[i-1])
        continue; 
            path.push_back(nums[i]);
            solve(i+1,nums,path,ans,st);
            path.pop_back();
        }
    }
};