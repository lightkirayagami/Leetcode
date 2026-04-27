// Last updated: 27/04/2026, 21:48:14
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int islandPerimeter(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&visited[i][j]==0)
                {
                    ans= dfs(grid,i,j,m,n,visited);
                }
            }
        }
        return ans;
        
    }


    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&visited)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1)
        {
            return 1;
        }
        else if(visited[i][j]==1)
        {
            return 0;
        }
        visited[i][j]=1;
        int ans=0;

        for(int k=0;k<4;k++)
        {
            int x1=i+dx[k];
            int y1=j+dy[k];
            ans=ans+dfs(grid,x1,y1,m,n,visited);

        }
        return ans;
    }
  
};