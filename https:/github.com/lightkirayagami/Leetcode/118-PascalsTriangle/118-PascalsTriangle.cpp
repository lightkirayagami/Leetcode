// Last updated: 27/04/2026, 21:51:10
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int>row;
            if(i==0)
            {
                row.push_back(1);
                ans.push_back(row);
            }
            else if(i==1)
            {
                row.push_back(1);
                row.push_back(1);
                ans.push_back(row);

            }
            else
            { 
                row.push_back(1);
                for(int j=1;j<i;j++)
                {
                    int val=ans[i-1][j]+ans[i-1][j-1];
                    row.push_back(val);
                }
                row.push_back(1);
                ans.push_back(row);
            }
        }
        return ans;

        }
        
    
};