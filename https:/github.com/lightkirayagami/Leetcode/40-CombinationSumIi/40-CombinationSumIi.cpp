// Last updated: 27/04/2026, 21:52:37
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>path;
        sort(candidates.begin(),candidates.end());

        solve(candidates,0,target,path,ans);
        return ans;


        
    }


    void solve(vector<int>& candidates,int start,int target,vector<int>path,vector<vector<int>>&ans)

    {
        // if(target<0)
        // {
        //     return;
        // }
        if(target==0)
        {
            ans.push_back(path);
            return;
        }
        

        for(int j=start;j<candidates.size();j++)
        {
            if ((j > start && candidates[j] == candidates[j-1])||candidates[j]>target)
        continue;

            path.push_back(candidates[j]);
            solve(candidates,j+1,target-candidates[j],path,ans);
            path.pop_back();
        }
        return;



    }
};