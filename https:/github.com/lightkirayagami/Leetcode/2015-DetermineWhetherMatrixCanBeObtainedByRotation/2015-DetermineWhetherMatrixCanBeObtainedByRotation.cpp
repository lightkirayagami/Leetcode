// Last updated: 27/04/2026, 21:45:22
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         int m=mat.size();
      
      for(int k=0;k<4;k++)
      {
        for(int i=0;i<m/2;i++)
        {
            for(int j=i;j<m-i-1;j++)
            {
                int temp=mat[i][j];
                mat[i][j]=mat[m-j-1][i];
                mat[m-j-1][i]=mat[m-i-1][m-j-1];
                mat[m-i-1][m-j-1]=mat[j][m-i-1];
                mat[j][m-i-1]=temp;
            }
            
        }
          if(mat==target)
          {
              return true;
          }
      }
         
       
        return false;
        
    }
};