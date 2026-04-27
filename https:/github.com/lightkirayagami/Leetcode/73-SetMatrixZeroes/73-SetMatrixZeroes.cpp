// Last updated: 27/04/2026, 21:52:01
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();


        vector<pair<int,int>>nums;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    nums.push_back({i,j});
                }
            }
        }



        for(int k=0;k<nums.size();k++)
        {
            pair<int,int>p=nums[k];
            int x=p.first;
            int y=p.second;


            for(int i=0;i<n;i++)
            {
                matrix[x][i]=0;
            }

            for(int j=0;j<m;j++)
            {
                matrix[j][y]=0;
            }
        }

        
        
    }
};