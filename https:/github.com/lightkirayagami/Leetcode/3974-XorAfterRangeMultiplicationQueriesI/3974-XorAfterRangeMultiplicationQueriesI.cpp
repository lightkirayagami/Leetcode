// Last updated: 27/04/2026, 21:44:32
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod=pow(10,9)+7;
        int n=queries.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            for(int j=l;j<=r;j=j+k)
            {
                nums[j] = ((long long)nums[j] * v) % mod;
            }
        
        }


        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;        
    }
};