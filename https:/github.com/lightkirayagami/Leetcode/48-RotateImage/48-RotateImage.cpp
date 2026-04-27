// Last updated: 27/04/2026, 21:52:29
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                else
                {
                    if(i<j)
                    {
                        swap(matrix[i][j],matrix[j][i]);
                    }
                }
            }

        }


        for(auto &v :matrix)
        {
            reverse(v.begin(),v.end());
        }
        // return matrix;


        
    }
};